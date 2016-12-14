#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class List
{
    protected:

    struct Record
    {
        // last name as a string, sort key
        string last;

        // first name as a string
        string first;

        // phone number as a string
        string phone;

        // Not necessary in array based implementation
        Record* next;
    };

    public:
    // inserts a new record into the list,
    //    using last as the key.  The list should be in
    //    ascending order. parameter order: last, first, phone.
    virtual void insert( string, string, string ) = 0;
    // removes the first record with the key that matches the argument
    virtual void remove( string ) = 0;
    // destroys the list.
    virtual void clear() = 0;

    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    // searches for the record with the key that matches the argument.
    //    returns relative position of the element if found, -1 otherwise.
    //    0 is 1st item, 1 is second, 2 is third, etc
    //    implemented as binary search for the array list,
    //    sequential search for the linked list implementation.
    virtual int search( string ) const = 0;
    // returns the number of records in the structure.
    virtual int length() const = 0;
    // displays the contents of the structure to the screen.
    virtual void print() const = 0;
};


#endif // LIST_H_INCLUDED
