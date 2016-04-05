Optimizing Oberon-2 Compiler
============================

Contents

* [Introduction](#intro)
* [OO2C: The Oberon-2 to ANSI-C Translator](#oo2c)
* [The OOC Reference Manual](#OOCref)
* [Miscellaneous](#misc)
* [Download](#download)

[<a id="intro"></a>Introduction]()
----------------

In short, OOC is an Internet based project providing an Oberon-2 development platform. It consists of

-   an optimizing compiler,
-   a number of source code and compiler related tools,
-   a set of standard library modules, and
-   a reference manual.

The programming language Oberon-2 is defined in the [March 1995 report](ftp://ftp.inf.ethz.ch/pub/software/Oberon/OberonV4/Docu/Oberon2.Report.ps.gz), available from the ftp server of the ETH Zürich. The compiler is built around an innovative intermediate code representation called GSA (see \[[Bra95](ftp://ftp.inf.ethz.ch/pub/publications/dissertations/th11024.ps.gz)\]). GSA stands for \`guarded single-assignment form'. It combines \`static single-assignment form' (SSA) with a new way of encoding control flow. The major characteristic of SSA is that its instructions operate on values that are passed from a generating instruction to instructions that use it as an argument. SSA does not know variables or assignments to variables, nor does it impose a strict ordering of instructions.

The flexible nature of the GSA code representation allows for efficient code improving transformations on the intermediate code. Due to its special properties, it is quite easy to implement optimizations like constant propagation, copy propagation, procedure inlining, or common subexpression elimination, just to name a few. The compiler front-end translates directly to GSA. It is retargetable, that is, it can be adjusted to suit different target platforms. A prototype back-end exists, using ANSI-C as the target language. This back-end is used by OO2C, the generic OOC compiler for the Unix platform.

[<a id="oo2c"></a>OO2C: The Oberon-2 to ANSI-C Translator]()
-------------------------------------------

OO2C is the generic OOC compiler for the Unix platform. It is an Oberon-2 to ANSI-C translator and runs on any 32 bit Unix system with an ANSI-C compiler (including Linux, HP-UX, SunOS, and Solaris). Installation is based on GNU autoconf, which guarantees smooth and convenient installation across all supported systems. An experimental compiler for 64 bit systems exists. Get the one of the *oo2c\_32* tar files for 32 bit systems, and *oo2c\_64* for 64 bit systems like the DEC Alpha.

OO2C can use two add-on packages to expand its own capabilities: Hans-J. Boehm's conservative garbage collector [gc](http://www.hboehm.info/gc/) and GNU [libtool](ftp://ftp.gnu.org/pub/gnu/libtool). The garbage collector extends OO2C's run-time system with the ability to free unused heap objects. With the help of libtool, OO2C can create shared and static libraries from a set of modules. Please refer to the chapter "Installing OO2C" in Part II of the [OOC Reference Manual](http://ooc.sourceforge.net/OOCref/OOCref_toc.html) for information on how to use these packages.

The OO2C distribution is available [here](http://sourceforge.net/project/showfiles.php?group_id=3539).

[<a id="OOCref"></a>The OOC Reference Manual]()
----------------------------

The OOC Reference Manual provides complete supporting documentation for the OOC library and OOC compilers (including OO2C). Part I covers the standard library modules in detail, and gives examples for their use. Part II provides information about the language accepted by OOC compilers, OOC pragmas, and installation and use of OO2C.

For questions, comments, or suggestions regarding the manual you can contact the authors:

|                    |                                              |
|--------------------|----------------------------------------------|
| Part I (Library)   | [Eric Nikitin](mailto:enikitin@apk.net)      |
| Part II (Compiler) | [Michael van Acken](mailto:mva@users.sf.net) |

Please note: Most chapters (about 90%) of the reference manual are finished, but it is still a work in progress.

The HTML version of the manual is [here](http://ooc.sourceforge.net/OOCref/OOCref_toc.html). The OO2C distribution includes the manual's \`texinfo' source and the derived \`info' files. The sources and additional output formats (including Postscript) are also available separately in the [OOCref tar file](http://prdownloads.sourceforge.net/ooc/).

[<a id="misc"></a>Miscellaneous]()
-----------------

The **ooc-compiler** mailing list has been set up as a discussion place for developers, and for the announcement of new releases. The mailing list resides on SourceForge. You can subscribe via [this page](http://sourceforge.net/mail/?group_id=3539).

Past postings to the mailing list are available in the [archive](http://www.geocrawler.com/redir-sf.php3?list=ooc-compiler), very old postings are [here](ooc-list/threads.html).

If you want to contribute to OOC, or have questions, send mail to <mva@users.sf.net>.

------------------------------------------------------------------------

[<a id="download"></a>Download Servers]()
--------------------

|                                                                           |
|---------------------------------------------------------------------------|
| [SourceForge](http://sourceforge.net/project/showfiles.php?group_id=3539) |

Links
-----

-   OOC Project page at [SourceForge](http://sourceforge.net/project/?group_id=3539)
-   [oo2c for mingw32](https://web.archive.org/web/20060620112920/http://espc22.murdoch.edu.au/~stewart/files/) by Stewart Greenhill
-   [Oberon Implementations and Internet Resources list](https://web.archive.org/web/20040405070138/http://www.math.tau.ac.il/~guy/Ob-pkgs.html)
-   A [list of projects](https://web.archive.org/web/20010815095151/http://www.informatik.uni-oldenburg.de/~crash/oberon.html) based on OOC
-   [VisualOberon](http://visualoberon.sourceforge.net/), a GUI class library for X11
-   [XML Parser for OOC](https://sourceforge.net/projects/ooc/files/libxml/)
-   [Draft ADT Library](http://ooc.cvs.sourceforge.net/viewvc/ooc/libadt/) (see OOC mailing list for details)
-   [Hans-J. Boehm's gc](http://hboehm.info/gc/), the garbage collector used by oo2c
-   [XOO2C](https://web.archive.org/web/20060503054852/http://www.sbox.tugraz.at/home/c/crf/xoo2c.html): oo2c/DOS (native 32-bit DOS compiler) and Crossoo2c (Linux -&gt; Win/DOS crosscompilers)
-   [Crosscompiler](https://web.archive.org/web/20060620112920/http://espc22.murdoch.edu.au/~stewart/files/) for the Atmel AVR RISC architecture

------------------------------------------------------------------------

Michael van Acken [mva@users.sf.net](mailto:mmva@users.sf.net)
