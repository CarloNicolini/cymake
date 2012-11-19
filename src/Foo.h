/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <nicolini.carlo@gmail.com> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return
* ----------------------------------------------------------------------------
*/

#ifndef _FOO_H_
#define _FOO_H_

#include <iostream>
#include "Bar.h"

class Foo : public Bar
{
public:
    Foo()
    {
        std::cerr << "Foo base constructor" << std::endl;
        barval=0;
        fooval=-10;
    }
    Foo(int x)
    {
        std::cerr << "Foo (int) constructor" << std::endl;
        this->barval=x;
        this->fooval=1.0;
    }

    double fooval;
};

#endif
