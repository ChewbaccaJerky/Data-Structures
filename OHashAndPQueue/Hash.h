#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Hash
{
    protected:
    // the hash function accepts the key string and returns the index of the
    // corresponding element.
    virtual int hash( string ) const = 0;

    public:
    // inserts a key into the hash table. Returns 0 if successful, -1 otherwise
    virtual int insert( string ) = 0;
    // removes a key from the hash table. Returns 0 if successful, -1 otherwise
    virtual int remove( string ) = 0;
    // search for the key in the hash table. Returns true if found,
    //      false otherwise
    virtual bool search( string ) const = 0;
    // returns true if the hash table is full.
    virtual bool isFull() const = 0;
    //returns true if the hash table is empty
    virtual bool isEmpty() const = 0;
    // displays the contents of the hash table to the screen
    virtual void print() const = 0;
    // clears the hash table
    virtual void clear() = 0;
};


#endif // HASH_H_INCLUDED
