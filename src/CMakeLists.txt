#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# <nicolini.carlo@gmail.com> wrote this file. As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return
# ----------------------------------------------------------------------------
#

project(cymake)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)
# here you must put the .pyx wrappers and set the property CYTHON_IS_CXX
set( PYTHON_WRAPPERS_SRC
test1.pyx
)

set(CYMAKE_SRC
)

set(CYMAKE_HDRS
Foo.h Bar.h Qux.h
)

set_source_files_properties( ${PYTHON_WRAPPERS_SRC} PROPERTIES CYTHON_IS_CXX 1 )
# In this following command you must put the cython wrapper and then the implementation of the classes used (NOT THE CXX!)
cython_add_module( test1 test1.pyx ${CYMAKE_HDRS} )

