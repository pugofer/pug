
# Table of Contents

1.  [The Name](#orgf751d37)
2.  [Acknowledgements](#orgd900071)
3.  [Syntax late-bound](#orgb5a9b32)
4.  [Building](#orgcb61d47)
5.  [Literature](#orgea93683)

This is the umbrella directory for Pugofer.
It contains

-   the sources for the executable `pug` including install instructions
-   techreports
-   editor modes (currently emacs)


<a id="orgf751d37"></a>

# The Name

-   **Pugofer = Platonic Universe that's GOod for Equational Reasoning:** The ideas, philosophy, methodology, habits, culture that we believe should be the foundation of good programming education
-   **Pug = Platonic Universe for Geeks:** The executable that's its most standard interface.
    
    More on the recent history at the blog posts : [Pugofer-Pug](http://blog.languager.org/2022/03/pugofer-pug.html), [A Fairy Tale and a Bridge](http://blog.languager.org/2022/03/a-fairy-tale-and-bridge.html)
    
    Older writings at [on FP](http://blog.languager.org/search/label/FP) may also be of interest


<a id="orgd900071"></a>

# Acknowledgements

Mark Jones original creation of gofer is the starting point for this work and is gratefully acknowledged

The alternate prelude [pusimple](pusimple.pre) is particularly neat for those who feel the need to grok Hindley-Milner before getting into typeclasses. With that you'll get, for example:

    ? :t (+)
    (+) : Int -> Int -> Int
    ? :t (==)
    (==) : a -> a -> Bool


<a id="orgb5a9b32"></a>

# Syntax late-bound

You can switch back to classic Haskell syntax with `:s -S`

    ? map.(1+).[1,2,3]
    [2, 3, 4] : [Int]
    
    ? :s -S
    ? map (1+) [1,2,3]
    [2, 3, 4] :: [Int]


<a id="orgcb61d47"></a>

# Building

-   `cd src`
-   Choose the architecture near line 25 following  [prelude.h](src/prelude.h)
    
    Exactly one `LINUX`, `WIN32` or `NETBSD` (for MacOS) should be 1; all the rest should be 0
-   If necessary, choose C compiler &#x2013; `CC` &#x2013; in [Makefile](src/Makefile)
-   `$ make`

There is no configure to run.  
Windows seems to build with mingw for 32 bit but not 64.


<a id="orgea93683"></a>

# Literature

Justifications for these changes are explained in [Notes on Notation](http://www.the-magus.in/Publications/notation.pdf)

Also may be of interest:

-   [Thought Dialogue with EWD](http://www.the-magus.in/Publications/ewd.pdf)
-   [Doting on the Dot](http://www.the-magus.in/Publications/DotingOnTheDot.pdf)
-   [Lunchtime at Purgatory](http://www.the-magus.in/Publications/purgatory.pdf)

Evidently at the end of his life Dijkstra did [support FP](https://www.cs.utexas.edu/users/EWD/OtherDocs/To%20the%20Budget%20Council%20concerning%20Haskell.pdf)

