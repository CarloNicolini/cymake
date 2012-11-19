cymake
======

A base example to bring your c++ class hierarchy in cython and create a python module

This simple project needs to be built with CMake > 2.6 and the latest version of cython (currently 0.17.1).

It explains how to do some interesting wrapping of C++ class hierarchies with Cython and how to get a Python module from them without too much pain.

Build on Linux
====
In order to build this project in a Ubuntu/Linux box you have to install:

1) gcc/g++ compiler and all its related libraries ( `sudo apt-get install build-essential` )
2) cmake > 2.6 (I suggest downloading the latest CMake from www.cmake.org rather than relying on the repositories)
3) cython > 0.17 ( download it from `http://cython.org/` otherwise if the repositories are up-to-date, make the usual `sudo apt-get install cython` )

You can try to build this project as follows: first enter the base directory

`cd cymake`

then issue the command

`cmake .`

(I suggest to make a Debug build of it, by explicitly specifying `cmake -DCMAKE_BUILD_TYPE=Debug .` )

The module `test1.so` will be build inside `cymake/build` folder.

You can test it copying the python demo `examples/test1.py` inside the `cymake/build` folder and then:

`python test1.py`

Build on OSX
===

The code is also tested on OSX with Cython, CMake and g++ installed. In order to get the latest cython version on OSX I warmly suggest to use MacPort version of it, because Fink version of cython is currently 0.16. The steps to follow are the same of the Linux version.