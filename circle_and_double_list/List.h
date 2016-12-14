/*
    The List class is an abstract base class that serves as a parent
    class for the classes you will write.  List stores integers in an
    ordered linked list implementation.  The specifics of the implementation
    will vary based on the data strucure you are implementing.  Read
    the instructions for each child class you will write carefully.
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;


class List
{
    protected:

    public:

    // inserts it's argument into the list. Returns 0 if successful,
    //  -1 otherwise.
    virtual int insert( int ) = 0;

    // removes the first record matching it's argument from the
    // list.  Returns 0 if successful, -1 otherwise.
    virtual int remove( int ) = 0;

    // searches the list for the first record matching it's argument.
    // returns true if found, false otherwise.
    virtual bool find( int ) const = 0;

    // returns true if the list is full, false otherwise
    virtual bool isFull() const = 0;

    // returns true if the list is empty, false otherwise
    virtual bool isEmpty() const = 0;

    // returns the current length of the list, as an integers
    virtual int getLength() const = 0;

    // returns the "next" value in the list through it's
    //   reference parameter. Returns 0 if successful, -1 other
    //   wise.  The first time getNext() is invoked, it should
    //   return the first item in the list.
    virtual int getNext( int& ) = 0;

    // resets the iterator to the first position in the list.
    virtual void reset() = 0;

    // deletes/clears/destroys the list
    virtual void clear() = 0;

    // displays the current list on a single line.
    virtual void print() const = 0;
};

#endif
