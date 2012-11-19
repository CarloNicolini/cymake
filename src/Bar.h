/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <nicolini.carlo@gmail.com> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return
* ----------------------------------------------------------------------------
*/

#ifndef _BAR_H_
#define _BAR_H_

#include <iostream>
class Bar
{
public:
    Bar()
    {
        std::cerr << "Bar constructor" << std::endl;
        barval=0;
    }

    Bar(int x)
    {
        std::cerr << "Bar constructor(int x)" << std::endl;
        barval=x;
    }

    int barval;

};

#endif
