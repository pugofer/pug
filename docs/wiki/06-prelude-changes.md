# 06 — Prelude changes

The notation changes are not just in the compiler — the **prelude itself is
rewritten** in the new syntax. Pug ships two prelude files in
[`langlevels/`](../../langlevels/), both written in Pug notation, and the
default is selected at build time. This page walks through how each notation
change shows up in the prelude source, using
[`langlevels/pug.pre`](../../langlevels/pug.pre) (class-free) and
[`langlevels/kit.pre`](../../langlevels/kit.pre) (with type classes) as
living examples.

## The two preludes

| File | Based on | Type classes? |
|---|---|---|
| [`langlevels/pug.pre`](../../langlevels/pug.pre) | Haskell 1.2 prelude | **No** — a stripped prelude for grokking Hindley-Milner without typeclasses (see [`README.org:12`](../../README.org:12)) |
| [`langlevels/kit.pre`](../../langlevels/kit.pre) | Gofer 2.28 standard prelude | Yes — overloaded `==`, `<=`, `show` etc. via type classes |

Both are written entirely in Pug notation. The header of each
([`pug.pre:10-11`](../../langlevels/pug.pre:10),
[`kit.pre:10-11`](../../langlevels/kit.pre:10)) credits the PU additions:

```
--    PU Additions
--    Copyright Rusi Mody 1995-2015.
```

## Dot application throughout

Every function definition uses the dot for application. Compare the
combinator block
([`pug.pre:49-80`](../../langlevels/pug.pre:49)) with the Gofer original
(RR-1030 §5):

```haskell
-- Pug (pug.pre)
const : a -> b -> a
const.k.x = k

id   : a -> a
id.x = x

curry : ((a,b) -> c) -> a -> b -> c
curry.f.a.b = f.(a,b)

uncurry : (a -> b -> c) -> (a,b) -> c
uncurry.f.(a,b) = f.a.b

flip : (a -> b -> c) -> b -> a -> c
flip.f.x.y = f.y.x
```

```haskell
-- Gofer (RR-1030 §5)
const :: a -> b -> a
const k x = k

id   :: a -> a
id x = x

curry :: ((a,b) -> c) -> a -> b -> c
curry f a b = f (a,b)
...
```

Note the chains: `curry.f.a.b` is `((curry . f) . a) . b`, parsed by the
left-associative dot and short-circuited by `sc()` (see
[01 — Dot application](01-dot-application.md)) into the application
`curry f a b`.

## The `;` composition operator

Because the dot is now application, the prelude introduces a **new
composition operator `;`** ([`pug.pre:76-77`](../../langlevels/pug.pre:76),
[`kit.pre:65-66`](../../langlevels/kit.pre:65)):

```haskell
(;)  : (a -> b) -> (b -> c) -> (a -> c)
(g ; f).x = f.(g.x)
```

and declares it at high precedence
([`pug.pre:31`](../../langlevels/pug.pre:31)): `infixr 9 ;`. This is the
role Gofer's `(.)` played; in Pug `(.)` is the application primitive
([`pug.pre:47`](../../langlevels/pug.pre:47)):

```haskell
primitive (.) "primApply" : (a -> b) -> a -> b
```

It is used in point-free style, e.g.
([`pug.pre:100-101`](../../langlevels/pug.pre:100)):

```haskell
any.p = map.p ; or
all.p = map.p ; and
```

## Type signatures use `:`

Every signature uses the single colon
([`pug.pre:49`](../../langlevels/pug.pre:49), etc.):

```haskell
const : a -> b -> a
```

and primitive declarations too
([`pug.pre:46`](../../langlevels/pug.pre:46)):

```haskell
primitive (.) "primApply" : (a -> b) -> a -> b
```

## Cons is `::`

List patterns and construction use `::`
([`pug.pre:227-238`](../../langlevels/pug.pre:227)):

```haskell
head.(x::_)      = x
last.[x]         = x
last.(_::xs)     = last.xs
init.(x::xs)     = x :: init.xs
(x::xs) ++ ys    = x::(xs++ys)
```

and the operator declaration
([`pug.pre:37`](../../langlevels/pug.pre:37)):

```haskell
infixr 5 ++, ::
```

## Arithmetic sequences use `...`

The comments in the prelude show the mapping
([`pug.pre:120-123`](../../langlevels/pug.pre:120)):

```haskell
enumFrom.n           = iterate.(1+).n                  -- [n...]
enumFromThen.n.m     = iterate.((m-n)+).n              -- [n,m...]
enumFromTo.n.m       = takeWhile.(m>=).(enumFrom.n)    -- [n...m]
enumFromThenTo.n.o.m = takeWhile.(...).(...)           -- [n,o...m]
```

So `[1...10]` is the Pug spelling of Gofer's `[1..10]`.

## Guards and `where` are unchanged

The control-structure syntax is *not* part of the notation change — guards
(`|`), `where`, `if`/`then`/`else`, `case`/`of`, `let`/`in` keep their Gofer
form. Only the application/cons/sigil tokens change. For example
([`pug.pre:207-214`](../../langlevels/pug.pre:207)):

```haskell
abs : Int -> Int
abs.x    | x >= 0  = x
         | x <  0  = - x

signum : Int -> Int
signum.x | x == 0  = 0
         | x > 0   = 1
         | x < 0   = -1
```

The `|` guards and the `=` are exactly as in Gofer; only `abs.x` (dot) and
`: Int -> Int` (single-colon sigil) differ.

## `kit.pre` adds type classes on top

[`kit.pre`](../../langlevels/kit.pre) is the same notation but with class
and instance declarations. The class machinery is Gofer's (RR-1030 §13-14)
unchanged; the bodies are simply written with dots. For example the
primitive comparisons
([`pug.pre:108-113`](../../langlevels/pug.pre:108)):

```haskell
primitive (==) "primGenericEq",
          (/=) "primGenericNe",
          (<=) "primGenericLe",
          (<)  "primGenericLt",
          (>=) "primGenericGe",
          (>)  "primGenericGt"   : a -> a -> Bool
```

and uses ([`pug.pre:115-118`](../../langlevels/pug.pre:115)):

```haskell
max.x.y | x >= y    = x
        | otherwise = y
min.x.y | x <= y    = x
        | otherwise = y
```

## How the prelude is selected

The prelude is loaded at startup; the file used is the one compiled in as
the default (see [`src/prelude.h`](../../src/prelude.h) and the build
discussion in [`README.org:30-35`](../../README.org:30)). The
[`langlevels/`](../../langlevels/) directory holds alternative language
levels (`pug.pre`, `kit.pre`, `cat.pre`, `flamefloat.pre`, `pup.pre`) so
different builds can ship different defaults while sharing the same
notation engine.

## Summary

| Notation feature | Prelude example | Location |
|---|---|---|
| dot application | `const.k.x = k` | [`pug.pre:50`](../../langlevels/pug.pre:50) |
| `;` composition | `(g ; f).x = f.(g.x)` | [`pug.pre:76-77`](../../langlevels/pug.pre:76) |
| `(.)` as apply primitive | `primitive (.) "primApply"` | [`pug.pre:47`](../../langlevels/pug.pre:47) |
| `:` type sigil | `const : a -> b -> a` | [`pug.pre:49`](../../langlevels/pug.pre:49) |
| `::` cons | `head.(x::_) = x` | [`pug.pre:227`](../../langlevels/pug.pre:227) |
| `...` arithmetic seq | `-- [n...]` | [`pug.pre:120`](../../langlevels/pug.pre:120) |
| guards/where unchanged | `abs.x | x >= 0 = x` | [`pug.pre:208`](../../langlevels/pug.pre:208) |
| classes (kit.pre) | `primitive (==) ... : a -> a -> Bool` | [`pug.pre:108`](../../langlevels/pug.pre:108) |
