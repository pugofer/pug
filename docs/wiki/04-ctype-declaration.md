# 04 — The `ctype` declaration

Pug adds a new **`ctype`** declaration for data types, more compact than
Gofer's `data` and tailored to the dot notation. It lets a type be declared
with its constructors listed by **name only**, each implicitly typed by
peeling arrows off a shared header type.

This is a *syntactic* extension on top of Gofer (RR-1030 §11 declares types
with `data`); the runtime/type-system representation is the same
`DATATYPE` tycon. The grammar and a small expansion pass turn the compact
form into the same constructor list `data` produces.

## The grammar

[`parser.y:137-155`](../../src/parser.y:137) adds the `CTYPE` keyword and
three new non-terminals:

```yacc
ctDecls : ctDecls ';' ctDecl   { $$ = gc3(appendOnto($1, $3)); }
        | ctDecl
        ;
ctDecl  : conids ':' type      { $$ = gc3(ct1Clause(intOf($2), $3, $1)); }
        ;
conids  : conids ',' conid     { $$ = gc3(cons($3, $1)); }
        | conid
        ;

topDecl : CTYPE type {typeLhs = $2;} WHERE '{' ctDecls close
          { defTycon(6, $1, checkTyLhs($2), $6, DATATYPE); typeLhs = NIL; }
        | CTYPE context IMPLIES typeLhs {typeLhs = $4;} WHERE '{' ctDecls close
          { defTycon(8, $1, $4, ap(QUAL, pair($2,$8)), DATATYPE); typeLhs = NIL; }
        ;
```

So the surface form is:

```
ctype T a where { x, y, z : Type }
```

or with a context:

```
ctype (Eq a) => T a where { x, y : Type }
```

The `ctDecl` rule parses a **comma-separated list of constructor names**
(`conids`) followed by `:` and a single `type`. The action calls
[`ct1Clause`](../../src/parser.y:916) to expand each name.

## The expansion: `ct1Clause` / `ct1Const`

The shared `type` after `:` is an arrow chain `A -> B -> ... -> R`. Each
constructor name gets a type built by peeling arrows from the *left* and
applying them to the name, until the remaining type matches the header
`typeLhs`. [`parser.y:916-942`](../../src/parser.y:916):

```c
static Cell local ct1Clause(int line, Cell type, Cell conids)
{
  push(NIL);
  for (; nonNull(conids); conids = tl(conids))
    top() = cons(ct1Const(line, type, hd(conids)), top());
  return pop();
}

static Cell local ct1Const(int line, Cell type, Cell conid)
{
  push(conid);
  for (; isArrow(type); type = rType(type))      /* peel arrows */
    top() = ap(top(), dupStruct(lType(type)));    /* apply to name */
  if (!tEquals(line, typeLhs, type)) {            /* must match header */
    ERROR(line) "ctype target " ETHEN
    ERREXPR(type);
    ERRTEXT " must match header\n" EEND;
  }
  return pop();
}
```

So for `ctype T a where { x, y : a -> T a }`, with `typeLhs = T a`:

- `ct1Const` for `x` starts with `x`, peels `a` -> applies: `x a`, peels
  `T a` -> the remaining type is `T a`, which `tEquals` the header. Result:
  the constructor `x` with type `a -> T a`.
- Same for `y`.

The final `defTycon(..., DATATYPE)` call is the same one `data` uses, so the
resulting tycon is indistinguishable from a `data` declaration at the type
system level.

## The helpers

[`parser.y:898-915`](../../src/parser.y:898) defines the small support layer:

```c
#define lType(x) (snd(fst(x)))   /* left  of an arrow  */
#define rType(x) (snd(x))        /* right of an arrow  */

static Bool local isArrow(Cell x) {
  return isPair(x) && isPair(fst(x)) && fst(fst(x)) == ARROW;
}

static Bool local tEquals(int line, Cell t1, Cell t2)
/* Assumes Conid ('.' Varid)* format */
{
  if (whatIs(t1) == AP && whatIs(t2) == AP)
    return isVar(arg(t1)) && isVar(arg(t2)) &&
           textOf(arg(t1)) == textOf(arg(t2)) &&
           tEquals(line, fun(t1), fun(t2));
  else
    return isCon(t1) && isCon(t2) && textOf(t1) == textOf(t2);
}

static Cell local dupStruct(Cell l) {
  return isAp(l) ? ap(dupStruct(fst(l)), dupStruct(snd(l))) : l;
}
```

`tEquals` is a structural equality that walks the `Conid ('.' Varid)*` shape
(the dot-application form of a type — see [05 — Dot application in
types](05-type-application-dot.md)). `dupStruct` deep-copies a type tree so
each constructor gets its own copy of the shared argument types.

## The `typeLhs` global

`typeLhs` is a parser-global set in the `topDecl` action
(`{typeLhs = $2;}`) before the `ctDecls` are parsed, and cleared after
(`typeLhs = NIL;`). It is the header type `T a` against which
`ct1Const`'s leftover type is checked. It is also GC-marked in
[`input.c:1216`](../../src/input.c:1216) (`mark(typeLhs); /*RPM*/`).

## Before / after

```haskell
-- Gofer (RR-1030 §11)
data T a = x a | y a

-- Pug: data still works, OR use ctype
data T a = x a | y a
ctype T a where { x, y : a -> T a }
```

The `ctype` form shines when several constructors share a long argument
signature: the signature is written once after `:` and distributed across
all the names.

## Summary

| Concern | Location | What it does |
|---|---|---|
| keyword + grammar | [`parser.y:137-155`](../../src/parser.y:137) | `CTYPE`/`ctDecls`/`ctDecl`/`conids` |
| expansion driver | [`parser.y:916-923`](../../src/parser.y:916) | `ct1Clause` |
| per-constructor peel | [`parser.y:929-942`](../../src/parser.y:929) | `ct1Const` |
| arrow helpers | [`parser.y:900-905`](../../src/parser.y:900) | `lType`/`rType`/`isArrow` |
| type equality | [`parser.y:906-915`](../../src/parser.y:906) | `tEquals` |
| deep copy | [`parser.y:924-927`](../../src/parser.y:924) | `dupStruct` |
| header global | [`parser.y:152ff`](../../src/parser.y:152), [`input.c:1216`](../../src/input.c:1216) | `typeLhs` |
