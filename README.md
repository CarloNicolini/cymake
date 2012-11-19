cymake
======

A base example to bring your c++ class hierarchy in cython and create a python module

This simple project needs to be built with CMake > 2.6 and the latest version of cython (currently 0.17.1).

It explains how to do some interesting wrapping of C++ class hierarchies with Cython and how to get a Python module from them without too much pain.

Source Download & Compilation
===== 
First, acquire the source code by cloning the git repository:

    git clone https://github.com/CarloNicolini/cymake.git

then follow the instructions here.

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
The output text of cmake should be something similar to:

    -- The C compiler identification is GNU
    -- The CXX compiler identification is GNU
    -- Check for working C compiler: /usr/bin/gcc
    -- Check for working C compiler: /usr/bin/gcc -- works
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working CXX compiler: /usr/bin/c++
    -- Check for working CXX compiler: /usr/bin/c++ -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Found Cython: /usr/local/bin/cython 
    -- Found PythonLibs: /usr/lib/libpython2.7.so 
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /home/user/cymake

The module `test1.so` will then be built inside `cymake/build` folder.

You can make a simple test of the `test1.so` module either loading it as it were a usual python module, on an interactive python shell:

    $> python
    Python 2.6.6 (r266:84292, Sep 15 2010, 16:22:56) 
    [GCC 4.4.5] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from test1 import pyQux as Qux
    q=Qux()
    q.methodcall()

or by directly calling your script or the `examples/test1.py` python script.

`python test1.py`

which should make the call of the `methocall` method of the class `Qux` and show the output of it.

In this little project you have to carefull choose the name of things. I choose the naming convention which sets the python wrappers of class `X` as `pyX`. Then when importing the module is better to import it using the `as` keyword in python, for example, here the C++ class `Qux` is wrapped in `test1.pyx` as `pyQux`. When I import it, is renamed in `Qux` as follows:

    from test1 import pyQux as Qux

This convention helps you to distinguish the C++/Python classes in your project.


Build on OSX
===

The code is also tested on OSX with Cython, CMake and g++ installed. In order to get the latest cython version on OSX I warmly suggest to use MacPort version of it, because Fink version of cython is currently 0.16. The steps to follow are the same of the Linux version.