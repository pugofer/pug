# Project Overview

## Pug - derived from Gofer

Pug, the target of this project is a tiny interpreter forked from Gofer, which was a system designed to teach functional programming and explore implementation ideas.

## Targets
The `pug` binary is expected to run on Windows, Mac and Linux. The primary development machine will be Linux.
At some point, we will add a WASM target for pug, to be compiled using emscripten.

## Code
The code is written in C in late 80s and early 90s.

## Artifacts
The `pug` binary (`pug.exe`) in windows is the primary artifact. The `langlevels` folder with all the files in it are part of `pug` for they are required on any machine where `pug` is run.

## Tests
The tests are written in Python and use pexpect (wexpect in Windows).

## CI/CD
We aim to have Pug built and tested as part of each push and when PRs are raised.
