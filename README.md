# XView

What is XView
-------------
XView (X Window-System-based Visual/Integrated Environment for Workstations)
is a user-interface toolkit to support interactive, graphics-based
applications running under the X Window System.  XView provides a set of
pre-built, user-interface objects such as canvases, scrollbars, menus, and
control panels.  The appearance and functionality of these objects follow
the OPEN LOOK Graphical User Interface (GUI) specification.  XView features
an object-oriented style Application Programmer's Interface (API) that is
straightforward and easy to learn.

Why is this code on Github?
--------------------------- 
For a long winded explation of why this repo exists, see [why.md](why.md)

The short version is:
Since xview (and hence olvwm) are no longer available on Debian/Ubuntu,
this is just a copy of the xview code previously available on Debian
\+ the existing Debian patches
\+ additional patches to get olvwm, olwm and clock working on 64-bit x86


For a list of recent changes, run `git log -p`

## BUILD/INSTALL

### 0. Install the build/header/library packages required for the build:
#### On distros other than Ubuntu:
For distros other than Ubuntu, run `make -n dep` and install the equivalents
of the packages listed in the output. The required packages are:
- xutils-dev # for `imake`, X Window System utility programs for development
- libx11-dev # X11 client-side library (development headers)
- libxt-dev #  X11 toolkit intrinsics library (development headers)
- libxext-dev # X11 miscellaneous extensions library (development headers)
- libxpm-dev # X11 pixmap library (development headers)
- bison # YACC-compatible parser generator
- flex # fast lexical analyzer generator

#### On Ubuntu:

`sudo make dep` _# Note: yeah, this only works on Ubuntu/compatibles._

### 1. Next, start off by cloning this repo:
`git clone https://github.com/olvwm/xview`

### 2. Now you are ready to start with the build. First cd into the repo:
`cd xview`

### 3. The default build is done by running make:
`make`

### 4. (An optional install step) If you want the generated binaries/libraries/header files in /usr/openwin:
`sudo make install`

## Testing olvwm under Xnest/Xephyr:
### Preparation:
You can run the window manager (or any of the other applications) by
using the absolute path or by appending /usr/openwin/bin to the PATH
(assuming the binaries have been installed there).

For the binaries that have libxview/libolgx library dependencies,
set LD_LIBRARY_PATH appropriately.
(If the `make install` step shown above was done, you just need to add
/usr/openwin/lib to LD_LIBRARY_PATH)

For example, assuming you are using bash and assuming everything has
been installed in /usr/openwin/{bin,lib}, add the following to your .bashrc:
```
    export PATH=$PATH:/usr/openwin/bin
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/openwin/lib
```
### Test run:
You can start the nested X server using:
`Xephyr :1 # or Xnest :1`

You can test the window manager within the nested X server by running:
`olvwm -f -display :1`

## To use olvwm as the default window manager:
See [olvwm on Ubuntu](http://mlab.no/blog/2015/11/olvwm-on-ubuntu/)

## LICENSE

All the source code copied over from Debian or patched using the Debian
patches is copyright by the authors or patch providers, as described in
copyright, legal notice or COPYING files in each program's top-level
directory and/or in the source files themselves.

All additional patches or contributions made on top of the existing code,
specifically, all changes that were made to the code after git commit id
6e1142503013ec9106199591b1353776a6b2bcf6
are licensed under GPLv3 as described in [LICENSE](LICENSE)
