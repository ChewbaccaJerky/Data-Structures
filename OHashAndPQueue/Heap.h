#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <iostream>
using namespace std;

class Heap
{
    protected:
    virtual void reheapup( int, int ) = 0;      // helper functions for
    virtual void reheapdown( int, int ) = 0;    //  maintaining order of heap

    public:
    // adds a value to heap top - returns 0 if successfull, -1 otherwise
    virtual int insert( int ) = 0;
    // removes a value from heap top through reference parameter.  Returns 0
    //  if successful, -1 otherwise.
    virtual int remove( int& ) = 0;
    virtual bool isEmpty() const = 0;           // returns true if heap empty
    virtual bool isFull() const = 0;            // returns true if heap full
    virtual void print() const = 0;             // prints contents of heap
    virtual void clear() = 0;		            // clears heap
};

#endif // HEAP_H_INCLUDED
