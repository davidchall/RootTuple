# RootTuple

RootTuple is a lightweight C++ library, providing FORTRAN subroutines which enable the output of ROOT n-tuples.
It was written specifically for high energy physics applications, since each element in the n-tuple can represent an event.

This is in no way supposed to replace the Les Houches Event File (LHEF) format.
Rather, it was created to allow FORTRAN programs to output fully differential cross section information as an n-tuple.
Selection cuts can then be applied to, and histograms filled from, this n-tuple.

A description of the subroutines provided is found in the documentation, together with a guide on how they may be used.

## Quick start installation

Firstly, we require ROOT to be installed on your system (you can download it [here](http://root.cern.ch/drupal/content/downloading-root)).
Then, during installation, RootTuple needs `root-config` to be in your `PATH` environment variable.
The easiest way to achieve this is to source the ROOT setup script (e.g. `thisroot.sh`).
There are two possible installation methods for RootTuple, both of which are further described in the documentation.

The recommended installation method uses the CMake build system v2.8.6 or higher (which can be downloaded [here](http://www.cmake.org/cmake/resources/software.html)).
This has the advantage that it assesses your FORTRAN compiler for its name mangling conventions, allows the installation to be separated from the source code and also produces a `RootTuple-config` executable.

```bash
tar -xzvf RootTuple-1.0.0.tar.gz
mkdir build; cd build
cmake -DCMAKE_INSTALL_PREFIX=<prefix> ../RootTuple-1.0.0
make
make install
```

The alternative installation uses a premade Makefile and assumes a particular name mangling convention (should work for g77, gfortran and ifort compilers):

```bash
tar -xzvf RootTuple-1.0.0.tar.gz
cd RootTuple-1.0.0
cp external/FC_namemangling.h src/
make
```
