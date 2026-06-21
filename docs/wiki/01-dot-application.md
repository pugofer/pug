# 01 — Dot application

The headline change of the Pug notation: **function application is written
`f.x`, not `f x`**. Juxtaposition is no longer an application; in new syntax
it is a *syntax error*.

This is the change Dijkstra argued for in [EWD 1300](https://www.cs.utexas.edu/users/EWD/ewd13xx/EWD1300.PDF)
(pg 8 onwards): juxtaposition is the most economical notation a language has,
and spending it on the single most common combinator (application) wastes it.
Pug spends it instead on **nothing** — it is simply illegal — and uses an
explicit dot.

## The application separator is a table

[`pug.c:4-5`](../../src/pug.c:4) defines the global flag and the separator
character as a two-element array indexed by `newSyntax`:

```c
Bool   newSyntax  = TRUE;
Char   apChar[2]  = {' ', '.'};
```

`apChar[FALSE]` is a space (the Gofer juxtaposition printer); `apChar[TRUE]`
is a dot. Every place that prints an application reads
`apChar[newSyntax]`, so the same code path serves both dialects.

## The dot is given function-application precedence

The dot is not a user-declared operator; it is *built in* to the syntax
table. [`storage.c:169-179`](../../src/storage.c:169) `syntaxOf()`:

```c
Syntax syntaxOf(t)
Text t; {
    int i;
    if (newSyntax && t == textDot)
        return mkSyntax(LEFT_ASS, FUN_PREC);   /* the dot */
    for (i=0; i<syntaxHw; ++i)
        if (tabSyntax[i].text==t) return tabSyntax[i].syntax;
    return defaultSyntax(t);
}
```

So `.` parses as a **left-associative operator at `FUN_PREC`** — exactly the
precedence Gofer gives to juxtaposition. `textDot` is interned once at
startup in [`input.c:1220`](../../src/input.c:1220):

```c
case INSTALL : input(RESET);
    textDot = findText(".");
    varDot  = mkVar(textDot);
    ...
```

and the [`isDot`](../../src/pug.h:4) macro (`textOf(op) == textDot`) is the
test used throughout the parser to recognise it.

## Parsing: `opapd` turns a dot-operator into a direct application

The expression grammar ([`parser.y:350-358`](../../src/parser.y:350)) parses
infix expressions with an operator in the middle:

```yacc
opExp   : pfxExp
        | pfxExp op pfxExp   { $$ = gc3(opapd($1,$2,$3)); }
        | opExp0             { $$ = gc1((*tidyInfix[newSyntax])($1)); }
        ;
```

The action macro [`opapd`](../../src/parser.y:41) is the heart of the change:

```c
#define opap(lArg,op,rArg)  (ap2(op,lArg,rArg))            /* operator ap */
#define opapd(lArg,op,rArg) (newSyntax && isDot(op) ? ap(lArg,rArg) :\
                             opap(lArg,op,rArg))
```

- In **old** syntax, or for any non-dot operator, `opapd` reduces to `opap`,
  building an operator-application node `ap2(op, lArg, rArg)` (the Gofer
  representation that `oTidyInfix` later rewrites).
- In **new** syntax, when the operator *is* the dot, it builds a **direct
  application node** `ap(lArg, rArg)` — the very node Gofer's evaluator,
  type-checker and printer already understand as application. No later
  rewriting is needed for the application itself.

## Juxtaposition is now a syntax error

The Gofer juxtaposition rule is [`parser.y:375-387`](../../src/parser.y:375):

```yacc
appExp   : appExp atomic
         {
            if (newSyntax)
            {
              ERROR(row) "Juxtaposition has no meaning. Use ."
              EEND;
            }
            else
              $$ = gc2(ap($1,$2));
         }
         | TRUNST atomic   { $$ = gc2(ap(RUNST,$2)); }
         | atomic          { $$ = $1; }
         ;
```

In new syntax, the `appExp atomic` production *rejects* juxtaposition with
the message *"Juxtaposition has no meaning. Use ."*. Application must come
through the `op` route (the dot) instead.

## Short-circuiting chains of dot-applications

Because the dot is parsed as an infix operator, a chain `f.x.y.z` first
becomes a nested *operator*-application tree that the precedence resolver
must tidy. The new-syntax resolver [`nTidyInfix`](../../src/parser.y:833)
is a near-copy of Gofer's [`oTidyInfix`](../../src/parser.y:758) with one
extra call inserted in the **reduce** branch and the final unwind:

```c
#ifdef __GNUC__
inline
#endif
static Void local sc(e) /*short circuit dot applications */
Cell e;
{
  Cell temp;
  temp = fun(e);
  if (isDot(fun(temp)))
     fun(e) = arg(temp);
}
```

`sc()` detects the shape `((e . op) ...)` where `op` is the dot and
collapses it to `(e ...)`, dropping the now-redundant dot operator node.
This is the `/*RPM*/`-marked addition at [`parser.y:879`](../../src/parser.y:879)
and [`parser.y:892`](../../src/parser.y:892). Without it, the resolver would
leave stray dot-operator nodes that `opapd` had already collapsed at the
leaves; `sc()` keeps the two views consistent as the precedence tower is
rebuilt.

## Printing applications with the dot

The printer is shared between dialects via `apChar[newSyntax]`. The two
relevant spots are [`output.c:466-475`](../../src/output.c:466) `putSimpleAp`
and [`output.c:435-447`](../../src/output.c:435) `putOverInfix`:

```c
static Void local putSimpleAp(e)  /* print application e0 e1 ... en */
Cell e; {
    if (isAp(e)) {
        putSimpleAp(maySkipDict(fun(e)));
        putChr(apChar[newSyntax]);   /* <-- '.' or ' ' */
        put(FUN_PREC,arg(e));
    }
    else
        put(FUN_PREC,e);
}
```

So a parsed application `f x y` is printed as `f.x.y` in new syntax and
`f x y` in old syntax, from the very same tree.

## Before / after

From [`langlevels/pug.pre:49-53`](../../langlevels/pug.pre:49):

```haskell
-- Pug (new syntax)
const : a -> b -> a
const.k.x = k

id   : a -> a
id.x = x
```

vs. the Gofer original (RR-1030 §5):

```haskell
-- Gofer (old syntax)
const :: a -> b -> a
const k x = k

id   :: a -> a
id x = x
```

## Summary

| Concern | Location | What it does |
|---|---|---|
| flag + separator char | [`pug.c:4-5`](../../src/pug.c:4) | `newSyntax`, `apChar[]` |
| dot's syntax | [`storage.c:173-174`](../../src/storage.c:173) | `.` = left-ass, `FUN_PREC` |
| intern `textDot` | [`input.c:1220`](../../src/input.c:1220) | startup |
| `isDot` test | [`pug.h:4`](../../src/pug.h:4) | macro |
| parse: `opapd` | [`parser.y:41-42`](../../src/parser.y:41) | dot -> direct `ap` |
| parse: reject juxtaposition | [`parser.y:375-384`](../../src/parser.y:375) | error in new syntax |
| parse: `sc()` short-circuit | [`parser.y:824-831`](../../src/parser.y:824) | collapse dot chains |
| parse: `nTidyInfix` | [`parser.y:833-896`](../../src/parser.y:833) | new-syntax resolver |
| print: `putSimpleAp` | [`output.c:466-475`](../../src/output.c:466) | `apChar[newSyntax]` |
| print: `putOverInfix` | [`output.c:435-447`](../../src/output.c:435) | `apChar[newSyntax]` |
