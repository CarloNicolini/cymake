"""
----------------------------------------------------------------------------
"THE BEER-WARE LICENSE" (Revision 42):
<nicolini.carlo@gmail.com> wrote this file. As long as you retain this notice you
can do whatever you want with this stuff. If we meet some day, and you think
this stuff is worth it, you can buy me a beer in return
----------------------------------------------------------------------------
"""

from libcpp.vector cimport vector
from libcpp.pair cimport pair
#####################################
##### Foo implementation ##########
#####################################
cdef extern from "Bar.h":
    cdef cppclass Bar:
        Bar(int x) except +
        int barval
                
cdef class pyBar:
    cdef Bar *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, x=None):
        if x is not None:
            self.thisptr = new Bar(x)
                
    def __dealloc__(self):
        del self.thisptr
    
    property val:
        def __get__(self):
            return self.barval
    
    
#####################################
##### Bar implementation ############
#####################################
cdef extern from "Foo.h":
    cdef cppclass Foo(Bar):
        double fooval
        
cdef class pyFoo(pyBar):
    pyFoo()
    property fooval:
        def __get__(self):
            return self.fooval

#####################################
##### Bar implementation ############
#####################################
ctypedef Foo* FooPtr
ctypedef Bar* BarPtr


cdef extern from "Qux.h":
    cdef cppclass Qux:
        Qux()
        vector[Foo] myVector
        vector[int] myVectorInt
        vector[int*] mm
        vector[Foo*] myFooPtrVec
        pair[FooPtr,BarPtr] myPair2


cdef class pyQux:   
        cdef Qux *thisptr
        cdef vector[Foo] myVector
        cdef pair[FooPtr,BarPtr] myPair2
        def __cinit__(self,junk=None):
            if junk is None:
                self.thisptr = new Qux()
        
        def __dealloc__(self):
            del self.thiptr
        
        def methodcall(self):
            xx = self.thisptr.myPair2
            print (xx.first).fooval
            print (xx.second).barval