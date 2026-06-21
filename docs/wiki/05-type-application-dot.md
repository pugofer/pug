# 05 — Dot application in type expressions

The dot notation is not only for value-level application — it is also the
**type-level** application operator. In Pug, a type is written `Tree.a` not
`Tree a`. This page documents the `pvarop` thread through the type grammar
and the `typeSyntaxChk` enforcement that makes juxtaposition of types
illegal in new syntax (just as it is for values).

## The problem this solves

In Gofer (RR-1030 Appendix A, the type grammar), type application is
juxtaposition: `Tree a`, `f (a -> b) x`, etc. Once value juxtaposition is
outlawed ([01 — Dot application](01-dot-application.md)), keeping type
juxtaposition would be an inconsistency. Pug therefore extends the dot to
types.

## The `pvarop` non-terminal

[`parser.y:147-149`](../../src/parser.y:147) introduces a new non-terminal
that is *an optional `VAROP`*:

```yacc
pvarop : VAROP   {$$ = gc1($1);}   /*RPM*/
       |          {$$ = gc0(NIL);}
       ;
```

In old syntax, `pvarop` is always empty (the `VAROP` alternative is never
taken because the lexer never produces a `VAROP` in a type position there);
types apply by juxtaposition as in Gofer. In new syntax, the `VAROP`
produced for the dot is threaded in.

## Where `pvarop` is threaded

It appears in three type productions.

**Type-definition LHS** ([`parser.y:167-170`](../../src/parser.y:167)):

```yacc
typeLhs : typeLhs pvarop VARID { typeSyntaxChk("type Lhs", $2);
                                 $$ = gc3(ap($1,$3)); }
        | CONID
        ;
```

So `T a` (old) becomes `T.a` (new): the `pvarop` between `T` and `a` is the
dot, and the action builds `ap($1, $3)` — a type application node, exactly
as Gofer's juxtaposition did, but now via the dot operator.

**Type expression** ([`parser.y:220-225`](../../src/parser.y:220)):

```yacc
ctype  : ctype pvarop atype { typeSyntaxChk("type expression", $2);
                              $$ = gc3(ap($1,$3)); }
       | atype
       ;
```

So `Tree a` (old) becomes `Tree.a` (new), and `f (a -> b) x` becomes
`f.(a -> b).x`.

**`ctype` constructor list** (the `ctDecl` rule, see
[04 — `ctype` declaration](04-ctype-declaration.md)) uses the same
`pvarop`-free `conids` form for the constructor names, but the shared `type`
after `:` is a full `type` and so uses `pvarop` internally.

## The enforcement: `typeSyntaxChk`

[`parser.y:944-956`](../../src/parser.y:944) is the type-level analogue of
the value-level "Juxtaposition has no meaning. Use ." check:

```c
static Void local typeSyntaxChk(String context, Cell token)
{
  if (newSyntax && !isDot(token))
  {
    ERROR(row) "Syntax Error in %s (application expected)", context EEND;
  }
  else if (!newSyntax && !isNull(token))
  {
    ERROR(row) "Syntax error in %s (unexpected %s)", context,
    textToStr(textOf(token)) EEND;
  }
}
```

- In **new** syntax, the `pvarop` slot must be the dot (`isDot(token)`); if
  it is any other operator (or, by the grammar, if juxtaposition somehow
  sneaks in), the error *"application expected"* is raised. This is what
  makes `Tree a` a syntax error in Pug.
- In **old** syntax, the `pvarop` slot must be **empty** (`isNull(token)`);
  any operator there is an "unexpected" token — i.e. classic Gofer type
  juxtaposition admits no operator, as ever.

So the same `pvarop` non-terminal serves both dialects, with `typeSyntaxChk`
policing which fillings are legal.

## The `tEquals` helper relies on the dot shape

The `ctype` type-equality check
[`tEquals`](../../src/parser.y:906) (see [04 — `ctype`
declaration](04-ctype-declaration.md)) explicitly assumes the parsed type is
in the `Conid ('.' Varid)*` shape:

```c
/* Assumes Conid ('.' Varid)* format */
static Bool local tEquals(int line, Cell t1, Cell t2) {
  if (whatIs(t1) == AP && whatIs(t2) == AP)
    return isVar(arg(t1)) && isVar(arg(t2)) &&
           textOf(arg(t1)) == textOf(arg(t2)) &&
           tEquals(line, fun(t1), fun(t2));
  else
    return isCon(t1) && isCon(t2) && textOf(t1) == textOf(t2);
}
```

It recurses down the `fun` spine comparing `arg` leaves, which is exactly
the shape `Tree.a` parses to. This is why the `ctype` validation is
straightforward in Pug and would need a different walker in old syntax.

## Before / after

```haskell
-- Gofer (RR-1030 Appendix A)
type Lhs :  typeLhs varid            -- juxtaposition
type     :  ctype                    -- juxtaposition
ctype   :  ctype atype

-- Pug
type Lhs :  typeLhs pvarop VARID     -- pvarop = the dot
type     :  ctype pvarop atype
```

Concrete types:

```haskell
-- Gofer
Tree a
f (a -> b) x
(a,b) -> c

-- Pug
Tree.a
f.(a -> b).x
(a,b) -> c          -- tuples/arrow are not application, no dot needed
```

## Summary

| Concern | Location | What it does |
|---|---|---|
| `pvarop` non-terminal | [`parser.y:147-149`](../../src/parser.y:147) | optional `VAROP` (the dot) |
| type LHS rule | [`parser.y:167-170`](../../src/parser.y:167) | `typeLhs pvarop VARID` |
| type expr rule | [`parser.y:220-225`](../../src/parser.y:220) | `ctype pvarop atype` |
| enforcement | [`parser.y:944-956`](../../src/parser.y:944) | `typeSyntaxChk` |
| `tEquals` shape assumption | [`parser.y:906-915`](../../src/parser.y:906) | `Conid ('.' Varid)*` |
