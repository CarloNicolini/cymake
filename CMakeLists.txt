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

# COMANDI PER SPOSTARE I FILE DI BUILD (eseguibili di test e librerie ) DENTRO LA CARTELLA ./build
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(PROJECT_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE PATH "Single directory for all libraries")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE PATH "Single directory for all executables")

include( UseCython )
add_custom_target( ReplicatePythonSourceTree ALL ${CMAKE_COMMAND} -P
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ReplicatePythonSourceTree.cmake
  ${CMAKE_CURRENT_BINARY_DIR}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
###### ADD SOME OPTIMIZATION FLAGS FOR G++ COMPILER (which is found on Unix )
#if ( UNIX )
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -pipe -msse3 -fomit-frame-pointer -funroll-loops ")
#set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g2 -ggdb -Wall -Wextra -ansi -Wunused-function -Wunused-label -Wuninitialized -DDEBUG")
#endif ( UNIX )

####### Push more optimization options with MSVC compiler
# Push more optimization options with Microsoft Compiler
#if(MSVC)
# _WIN32, _NOMINMAX, disable some stupid warnings and enable multiprocessor compilation (/MP)
#ADD_DEFINITIONS(-D_WIN32 -D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_DEPRECATE -DNOMINMAX)
#ADD_DEFINITIONS("/EHsc /wd4127 /wd4505 /wd4714 /wd4800 /wd4181 /wd4244 /wd4996 /MP")
# This push some other optimizations in order: Full optimization (Ox), omit frame pointer (Oy), Enable FiberSafe optimizations(GT),
# Whole Program Optimization (/GL), OpenMP support (/openmp), NONdynamic runtime libraries (MT)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS} /arch:SSE2 /Ox /Oy /GT /GL")
# Specify to use multithreaded debug (non dynamic)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS}")
#endif(MSVC)


# Add the subdirectory with all the needed sources
add_subdirectory(src)

