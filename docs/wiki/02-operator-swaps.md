# 02 — Operator swaps

With juxtaposition freed from application, Pug repurposes the colon family of
symbols. The swap is **table-driven**: each repurposed symbol is a two-element
string array indexed by `newSyntax`, so the lexer, the type system and the
printer all read the active spelling from one place.

## The paired arrays

[`pug.c:6-9`](../../src/pug.c:6) defines four arrays, each `{old, new}`:

```c
String typeStr[2] = {"::", ":"};;   /* type signature   */
String consStr[2] = {":", "::"};;  /* list cons         */
String bindStr[2] = {"bind", ".."}; /* monad bind       */
String uptoStr[2] = {"..", "..."};  /* arithmetic upto  */
```

| Construct | `newSyntax=FALSE` (Gofer) | `newSyntax=TRUE` (Pug) | Array |
|---|---|---|---|
| Type signature `e :: T` / `e : T` | `::` | `:` | `typeStr` |
| List cons `x : xs` / `x :: xs` | `:` | `::` | `consStr` |
| Arithmetic `[n..m]` / `[n...m]` | `..` | `...` | `uptoStr` |
| Monad `bind` / `..` | `bind` | `..` | `bindStr` |

The pattern is deliberate: in Pug, **`:` always means "has type"** and **`::`
always means "cons"**, removing the Gofer ambiguity where `:` is cons and
`::` is the type sigil. The `..` token, freed from arithmetic sequences (now
`...`), is spent on the monad `bind`.

## Interning the active spellings at startup

[`input.c:1219-1230`](../../src/input.c:1219) interns the `Text` (interned
string) for each spelling under both dialects, so a toggle later can find
either one:

```c
case INSTALL : input(RESET);
    textDot           = findText(".");
    varDot            = mkVar(textDot);
    textCoco[FALSE]  = findText(typeStr[FALSE]);   /* "::" */
    textCoco[TRUE]   = findText(typeStr[TRUE]);      /* ":"  */
    textUpto[FALSE]  = findText(uptoStr[FALSE]);    /* ".." */
    textUpto[TRUE]   = findText(uptoStr[TRUE]);      /* "..." */
    textCons[FALSE]  = findText(consStr[FALSE]);    /* ":"  */
    textCons[TRUE]   = findText(consStr[TRUE]);     /* "::" */
    textBind[FALSE]  = findText(uptoStr[FALSE]);    /* ".."   -- NB: shares uptoStr */
    textBind[TRUE]   = findText(uptoStr[TRUE]);     /* "..."  -- NB: shares uptoStr */
    textCtype        = findText("ctype");
```

`textCoco` is the type-sigil `Text`, `textCons` the cons `Text`, `textUpto`
the arithmetic-sequence `Text`. (Note `textBind` reuses `uptoStr`'s strings;
the distinct `bindStr` array is used only at the type-system level — see
below.)

## The lexer dispatches on the active spelling

When the lexer reads an operator-shaped token, it compares the interned text
against the active sigils to decide which grammar token to emit.
[`input.c:1097-1116`](../../src/input.c:1097):

```c
if (isoneof(c0,SYMBOLS) || isoneof(c0,PRESYMBOLS)) {
    Text it = readOperator();

    if (it==textCoco[newSyntax])    return ':';        /* type sigil */
    if (it==textEq)                 return '=';
    if (it==textUpto[newSyntax])   return UPTO;        /* arithmetic upto */
    if (it==textAs)                 return '@';
    if (it==textLambda)             return '\\';
    if (it==textBar)                return '|';
    if (it==textFrom)               return FROM;
    if (it==textMinus)              return '-';
    if (it==textArrow)             return FUNARROW;
    if (it==textLazy)              return '~';
    if (it==textImplies)           return IMPLIES;
    ...
    top() = yylval = ap((opType==CONOP ? CONOPCELL : VAROPCELL),it);
    return opType;
}
```

So in new syntax, the literal `:` lexes as the `:` token (the type sigil),
and the literal `::` does *not* match `textCoco[TRUE]` so it falls through to
become a plain `CONOPCELL`/`VAROPCELL` — which is what the cons operator is.
Symmetrically in old syntax, `::` is the type sigil and `:` is the cons.

## The cons constructor is created under the active name

The list cons is a primitive constructor. [`type.c:1843`](../../src/type.c:1843)
creates it using the active spelling:

```c
nameCons = addPrimCfun(consStr[newSyntax], 2, 1,
                       mkPolyType(starToStar,
                                  fn(var, fn(typeList, typeList))));
```

So in new syntax the cons constructor is literally named `::`, and a pattern
`x :: xs` or expression `x :: xs` resolves to it. (See [03 — Syntax
toggle](03-syntax-toggle.md) for how this name is *renamed* when the dialect
is flipped at runtime.)

## The monad `bind` is looked up under the active name

[`type.c:1933`](../../src/type.c:1933) resolves the monad `bind` primitive
using `bindStr[newSyntax]`:

```c
nameBind = findName(findText(bindStr[newSyntax]));
```

In new syntax this looks up the name `..`; in old syntax, the name `bind`.
This is the only place `bindStr` (as opposed to `uptoStr`) is consumed, which
is why `textBind` in the lexer setup reuses `uptoStr`'s strings — the lexer
treats `..`/`...` as the arithmetic-sequence token, and the *type system*
separately knows the same text as the bind operator.

## Error messages use the active spelling

So that a parse error doesn't say "expected `::`" in Pug or "expected `:`"
in Gofer, the unexpected-token reporter renders the sigils via the arrays.
[`parser.y:567-578`](../../src/parser.y:567):

```c
case ':' :
   sprintf(buffer,"`%s'", typeStr[newSyntax]);
   return buffer;
...
case UPTO :
   sprintf(buffer,"`%s'", uptoStr[newSyntax]);
   return buffer;
```

## Before / after

From [`langlevels/pug.pre:30-37`](../../langlevels/pug.pre:30) (operator
declarations) and [`langlevels/pug.pre:46-47`](../../langlevels/pug.pre:46)
(a primitive type signature):

```haskell
-- Pug (new syntax)
infixr 5 ++, ::           -- cons is (::)
...
primitive (.) "primApply" : (a -> b) -> a -> b   -- type sig is (:)
```

vs. the Gofer original (RR-1030 §5, §10):

```haskell
-- Gofer (old syntax)
infixr 5 ++, :            -- cons is (:)
...
primitive (.) "primApply" :: (a -> b) -> a -> b  -- type sig is (::)
```

## Summary

| Concern | Location | What it does |
|---|---|---|
| paired arrays | [`pug.c:6-9`](../../src/pug.c:6) | `typeStr`/`consStr`/`bindStr`/`uptoStr` |
| intern spellings | [`input.c:1219-1230`](../../src/input.c:1219) | `textCoco`/`textCons`/`textUpto`/`textBind` |
| lexer dispatch | [`input.c:1100-1102`](../../src/input.c:1100) | `:` / `UPTO` tokens |
| cons constructor name | [`type.c:1843`](../../src/type.c:1843) | `consStr[newSyntax]` |
| monad bind name | [`type.c:1933`](../../src/type.c:1933) | `bindStr[newSyntax]` |
| error messages | [`parser.y:567-578`](../../src/parser.y:567) | `typeStr`/`uptoStr` |

See [03 — Syntax toggle](03-syntax-toggle.md) for how `consStr` is renamed
when the dialect is flipped while code is loaded.
