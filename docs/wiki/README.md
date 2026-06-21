# Pug Notation Wiki

This wiki documents the changes made to Mark Jones' **Gofer** (described in
`docs/RR-1030.pdf`, the Yale University Research Report RR-1030, "An
Introduction to Gofer") to produce **Pug** — a fork by Rusi Mody whose
justifications are set out in `docs/notation.pdf` ("Notes on Notation").

The motivating idea, drawn from Edsger W. Dijkstra's *Notational Conventions*
([EWD 1300](https://www.cs.utexas.edu/users/EWD/ewd13xx/EWD1300.PDF), pg 8 ff.),
is that **juxtaposition is too precious to spend on function application**.
Pug replaces it with an explicit **dot** (`.`) and re-uses the freed-up colon
family of symbols for type-related constructs.

## The notation changes at a glance

| Construct | Gofer (RR-1030) | Pug |
|---|---|---|
| Function application | juxtaposition `f x` | dot `f.x` |
| Type signature | `::` | `:` |
| List cons | `:` | `::` |
| Arithmetic sequence `upto` | `..` | `...` |
| Monad `bind` | `bind` | `..` |
| Type application | juxtaposition `Tree a` | dot `Tree.a` |
| Data-type declaration | `data` | `data` **and** new `ctype` form |

All of these are gated by a single global flag, `newSyntax`, which defaults to
`TRUE` and can be flipped at runtime with `:s -S` (and back with `:s +S`), so a
single binary speaks both dialects.

## Pages

1. [01 — Dot application](01-dot-application.md) — the `.` operator for
   function application: syntax table, parsing, short-circuiting, printing.
2. [02 — Operator swaps](02-operator-swaps.md) — the `:` / `::` / `..` /
   `...` / `bind` repurposing, driven by paired string arrays.
3. [03 — Syntax toggle](03-syntax-toggle.md) — the `:s ±S` runtime switch and
   the `renameName` re-hashing that keeps loaded code valid.
4. [04 — `ctype` declaration](04-ctype-declaration.md) — the new compact
   data-type form and its constructor expansion.
5. [05 — Dot application in types](05-type-application-dot.md) — the `pvarop`
   thread through the type grammar and its enforcement.
6. [06 — Prelude changes](06-prelude-changes.md) — how `pug.pre` and
   `kit.pre` are written in the new notation.

## How to read this wiki

Each page cites the exact source file and line of every change (e.g.
[`pug.c:4`](../../src/pug.c:4)) and gives short before/after examples. The
canonical examples of the new syntax in action are the prelude files
[`langlevels/pug.pre`](../../langlevels/pug.pre) (class-free) and
[`langlevels/kit.pre`](../../langlevels/kit.pre) (with type classes); see
[`README.org`](../../README.org) for the user-facing summary.

## References

- `docs/RR-1030.pdf` — Mark Jones, *An Introduction to Gofer*, Yale University
  Research Report RR-1030 (the baseline being modified).
- `docs/notation.pdf` — Rusi Mody, *Notes on Notation* (the changes being
  documented here).
- `docs/pu-additions` — one-line pointer to the above.
- Dijkstra, [EWD 1300](https://www.cs.utexas.edu/users/EWD/ewd13xx/EWD1300.PDF),
  *Notational Conventions*, pg 8 onwards — the original proposal for the dot.
