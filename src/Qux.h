/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <nicolini.carlo@gmail.com> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return
* ----------------------------------------------------------------------------
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include "Bar.h"
#include "Foo.h"

typedef std::vector<Foo*> FooRand;

typedef Foo* FooPtr;
typedef Bar* BarPtr;


using namespace std;
#define TOTAL_N 3
class Qux
{
public:
    Qux()
    {
        std::cerr << ":::: Qux base constructor ::::" << std::endl;
        myVector.resize(TOTAL_N);
        myVectorInt.resize(TOTAL_N);
        mm.resize(TOTAL_N);
        myFooPtrVec.resize(TOTAL_N);
        //myVectorOfPairs.resize(TOTAL_N);

        myPair2.first = new Foo();
        myPair2.second = new Bar();

        for (int i=0; i<TOTAL_N; i++)
        {
            myVector[i]=Foo(i);
            myVectorInt[i]=i;
            mm[i] = new int[2];
            for (int k=0; k<2; k++)
                mm[i][k]=rand()%10;
            myFooPtrVec[i] = new Foo();

            //myVectorOfPairs[i]=std::pair<Foo*,Bar*>(1, new Bar());
        }
    };
    ~Qux()
    {
        std::cerr << ":::: Qux  destructor ::::" << std::endl;
        //delete myPair.first;
        
        delete myPair2.first;
        delete myPair2.second;
        
        for (int i=0; i<TOTAL_N; i++)
        {
            delete[] mm[i];
            delete myFooPtrVec[i];
            //delete myVectorOfPairs[i].first;
            //delete myVectorOfPairs[i].second;
        }
    }

    std::vector<Foo> myVector;
    std::vector<int> myVectorInt;
    std::vector<int*> mm;
    FooRand myFooPtrVec;
    std::pair<FooPtr,BarPtr> myPair2;
    
    //std::vector< std::pair< Foo*, Bar* > > myVectorOfPairs;

};
