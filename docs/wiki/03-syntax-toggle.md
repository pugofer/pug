# 03 — Syntax toggle

A single Pug binary speaks **both** dialects — classic Gofer/Haskell syntax
and the new Pug notation — selected at runtime by the `newSyntax` flag. This
page documents the `:s ±S` command and the non-trivial part: renaming the
cons constructor *while code is loaded* so the toggle is not just a
printer/lexer switch but a true live rename.

## The flag and its default

[`pug.c:4`](../../src/pug.c:4):

```c
Bool   newSyntax  = TRUE;
```

Pug boots in the new notation. The flag is global and read by the lexer
([`input.c:1100`](../../src/input.c:1100)), the parser
([`parser.y:41`](../../src/parser.y:41)), the syntax table
([`storage.c:173`](../../src/storage.c:173)), the type system
([`type.c:1843`](../../src/type.c:1843)) and the printer
([`output.c:442`](../../src/output.c:442)) — see the other pages for each.

## The `:s` command registers `S`

The `:set` command table in [`gofer.c:202`](../../src/gofer.c:202) registers
the toggle:

```c
{'S', "PU syntax", &newSyntax}, /*RPM*/
```

So `:s +S` sets `newSyntax = TRUE` (Pug notation) and `:s -S` sets it
`FALSE` (classic Gofer). The user-facing example in
[`README.org:19-29`](../../README.org:19):

```
? map.(1+).[1,2,3]
[2, 3, 4] : [Int]

? :s -S
? map (1+) [1,2,3]
[2, 3, 4] :: [Int]
```

Note the output spelling flips too (`:` vs `::` for the type sigil) because
the printer reads `apChar`/`typeStr` via `newSyntax`.

## The option handler broadcasts `CHANGE_SYNTAX`

The actual work is in [`commonui.c:136-139`](../../src/commonui.c:136)
`processOption`:

```c
case 'S' :
  newSyntax = state;
  everybody(CHANGE_SYNTAX);
  return;
```

`everybody(CHANGE_SYNTAX)` is Gofer's "notify every subsystem" hook (the same
mechanism used for `+t`/`-t` etc.). Each subsystem's `everybody` case handles
`CHANGE_SYNTAX` as it sees fit. The only subsystem that needs to *do*
something is the type system, because of the cons constructor rename.

## The type system's `CHANGE_SYNTAX` case: `renameName`

[`type.c:1955-1957`](../../src/type.c:1955):

```c
case CHANGE_SYNTAX:
    renameName(textCons[!newSyntax], textCons[newSyntax]);
    break;
```

`textCons[!newSyntax]` is the *old* cons spelling, `textCons[newSyntax]` the
*new*. So flipping `newSyntax` from `TRUE` to `FALSE` calls
`renameName(textCons[TRUE] /* "::" */, textCons[FALSE] /* ":" */)`, and
vice-versa. This renames the already-created cons constructor in the name
hash table so that source loaded under the previous dialect continues to
resolve.

## `renameName` re-hashes the name

[`storage.c:1382-1414`](../../src/storage.c:1382) walks the name hash table
and physically moves the `Name` node from the old hash bucket to the new one,
then overwrites its `text`:

```c
Void renameName(Text oldTxt, Text newTxt)
{
  Int ho, hn;
  Name o, n, p;

  if (oldTxt == newTxt) return;

  o = nameHash[ho = nHash(oldTxt)];
  n = nameHash[hn = nHash(newTxt)];

  if (o != n) {                          /* different hash buckets */
    for (p = NIL; nonNull(o) && name(o).text != oldTxt; o = name(o).nextNameHash)
      p = o;
    if (isNull(o)) return;               /* old name doesn't exist */
    if (isNull(p))                       /* old was head of its bucket */
      nameHash[ho] = name(o).nextNameHash;
    else                                 /* old was mid-bucket */
      name(p).nextNameHash = name(o).nextNameHash;
    name(o).nextNameHash = n;            /* splice into new bucket */
    nameHash[hn] = o;
  }
  name(o).text = newTxt;                 /* overwrite the text */
}
```

This is a **live rename**: the `Name` cell (which holds the cons
constructor's arity, type, etc.) is preserved; only its spelling changes. So
a prelude loaded as `x :: xs` (Pug) continues to work after `:s -S` as
`x : xs` (Gofer), and the same `Name` is found by either spelling.

## Why only the cons constructor needs renaming

The other swapped symbols are *lexical* — the type sigil `:`/`::`, the
arithmetic `..`/`...`, the monad bind `bind`/`..` — they are tokens, not
`Name`s, so flipping `newSyntax` is enough: the lexer re-dispatches on the
next token. The cons operator is the one swapped symbol that is a **real
named value** (a primitive constructor created by `addPrimCfun`), so its
`Name` must be renamed for the toggle to be sound on already-loaded code.

## Before / after

```
? :s +S          -- Pug notation
? :t (==)
(==) : a -> a -> Bool

? :s -S          -- classic Gofer
? :t (==)
(==) :: a -> a -> Bool
```

The same loaded `(==)` name is printed with `:` or `::` purely from
`typeStr[newSyntax]`; no reload is needed.

## Summary

| Concern | Location | What it does |
|---|---|---|
| flag default | [`pug.c:4`](../../src/pug.c:4) | `newSyntax = TRUE` |
| `:s` registration | [`gofer.c:202`](../../src/gofer.c:202) | `'S'` -> `&newSyntax` |
| option handler | [`commonui.c:136-139`](../../src/commonui.c:136) | set flag, broadcast |
| broadcast target | [`type.c:1955-1957`](../../src/type.c:1955) | `CHANGE_SYNTAX` case |
| rename primitive | [`storage.c:1382-1414`](../../src/storage.c:1382) | `renameName` re-hash |
| user docs | [`README.org:19-29`](../../README.org:19) | `:s -S` example |
