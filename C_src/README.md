# C source code - reputable references

Sometimes, I want to know how some C function I am using is actually implemented, for example, the standard C library function `memmove()`. This directory contains a collection of open source C code to use as a reference. Each directory contains a **Sublime Text project**, which is essential for quickly finding what I'm looking for.

* TODO -see bottom - decide where to commit - everything is .gitignored to begin with.

* Running list of C code that I want to see:
    * Standard C lib.
        * fopen()
        * struct FILE
        * printf()
        * memmove()
    * \#include <unistd.h>
        * getopt()
    * \#include <sys/mman.h> ?
        * shm_open()
    * \#include <pthread.h>?
        * pthread_create()


#  In this directory \[local to my machine for now\]

| Directory                  | What is it?                                                                                   | Where is it from?                                                                                               | Definitions confirmed to exist here. | Remarks                                                                                                                                                                                     |
|:--------------------------:|:---------------------------------------------------------------------------------------------:|:---------------------------------------------------------------------------------------------------------------:|--------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Linux/linux/include/linux/ | linux-headers-3.16.0-4-common Equivalent                                                      | [Linux kernel on github](https://github.com/torvalds/linux)                                                     | linux/list.h                         | [Important notes in my os_concepts_galvin/osc9e_src/README.md](https://github.com/darbinreyes/subparprogrammer/blob/master/textbooks/os_concepts_galvin/osc9e_src/README.md)                |
| Linux/linux                | Linux kernel source                                                                           | [Linux kernel on github](https://github.com/torvalds/linux)                                                     | linux/list.h                         | Repo. is huge. [Important notes in my os_concepts_galvin/osc9e_src/README.md](https://github.com/darbinreyes/subparprogrammer/blob/master/textbooks/os_concepts_galvin/osc9e_src/README.md) |
| Linux/glibc                | GNU C Library master sources                                                                  | [GNU sources](https://www.gnu.org/software/libc/sources.html)                                                   | ctype.h isalpha()                    |                                                                                                                                                                                             |
| Apple/darwin-xnu           | XNU kernel is part of the Darwin operating system for use in macOS and iOS operating systems. | [Darwin on github](https://github.com/apple/darwin-xnu)                                                         | shm_open(), <sys/mman.h>             | XNU is an acronym for X is Not Unix.                                                                                                                                                        |
| uwaterloo/os161-base-2.0.3 | An OS for teaching!                                                                           | [OS/161 Harvard Home Page](http://os161.eecs.harvard.edu) [dload page](http://os161.eecs.harvard.edu/download/) | memmove()                            | **Well Commented!**                                                                                                                                                                         |
| Apple/BerkeleyDB-24        | Berkeley DB: An embedded database programmatic toolkit.                                       | [Apple Open Source tarballs BerkeleyDB](https://opensource.apple.com/tarballs/BerkeleyDB/)                      | memmove()                            | Interesting to compare to OS/161 memmove().                                                                                                                                                 |
| Apple/Libc-1439.40.11      | Apple's implementation of "Libc"                                                              | [Apple Open Source tarballs LibC](https://opensource.apple.com/tarballs/Libc/)                                  | fopen()                              |                                                                                                                                                                                             |

# Search notes

Finding such code is surprisingly difficult, especially well commented code, but [this was my starting point](https://stackoverflow.com/questions/13339582/why-is-linux-memmove-implemented-the-way-it-is). After lots of searching, I arrived at the table above.

From there, these seemed to be the best sources (links are to the code for memmove() but see the parent URLs):

* [Nice source 1](https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memmove_8c_source.html)
    * Figuring out how to download this source code without doing it one file at a time.
        * Moving up a few directories: [a long list of files](https://student.cs.uwaterloo.ca/~cs350/common/). 
        * This reveals that the code is used at part of [some university course](https://student.cs.uwaterloo.ca/~cs350/W21/).
        * Notice "os161-1.99" in the main page, this is the [name of the whole project](https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/index.html).
        * What is os161? See [here "OS/161 Information"](https://student.cs.uwaterloo.ca/~cs350/W21/assignments/)
                * The [OS/161 home page](http://os161.eecs.harvard.edu/) at Harvard. **Gold?!**
* [Nice source 2](https://opensource.apple.com/source/BerkeleyDB/BerkeleyDB-6/db/clib/memmove.c)


# TODO - decide where to commit - everything is .gitignored to begin with.

    * Create a local copy of everything, put it in my own private repo. C_src?
    * Use git submodule?
    * Will I ever need to change this code? - probably to add my own comments....?
    * How will I keep my subl projects safe?
    * Definitely don't want to lose all the effort I put into finding all this shit.