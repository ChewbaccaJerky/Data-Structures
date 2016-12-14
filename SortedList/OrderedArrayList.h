#ifndef ORDEREDARRAYLIST_H_INCLUDED
#define ORDEREDARRAYLIST_H_INCLUDED

#include <iostream>     //cout and endl
#include <iomanip>      //setw
#include <string>
#include "List.h"

using namespace std;

const int CAP = 10;
class OrderedArrayList : public List
{
    private:
        Record* records;
        int l;          //length
    public:
        OrderedArrayList();
        ~OrderedArrayList();
        // inserts a new record into the list,
    //    using last as the key.  The list should be in
    //    ascending order. parameter order: last, first, phone.
        void insert( string, string, string );
    // removes the first record with the key that matches the argument
        void remove( string );
    // destroys the list.
        void clear();

        bool isFull() const;
        bool isEmpty() const;
    // searches for the record with the key that matches the argument.
    //    returns relative position of the element if found, -1 otherwise.
    //    0 is 1st item, 1 is second, 2 is third, etc
    //    implemented as binary search for the array list,
    //    sequential search for the linked list implementation.
        int search( string ) const;
    // returns the number of records in the structure.
        int length() const;
    // displays the contents of the structure to the screen.
        void print() const;

};

OrderedArrayList :: OrderedArrayList()
{
    records = new Record[CAP];
    l = 0;
}

OrderedArrayList :: ~OrderedArrayList()
{
    delete records;
}

void OrderedArrayList :: insert(string last, string first, string num)
{
    //empty list
    if( l == 0 )
    {
        records[l].last = last;
        records[l].first = first;
        records[l].phone = num;
        l++;
        return;
    }

    if( l == CAP - 1)
        return;

    int i;
    for( i = l - 1; i >= 0 && (records[i].last).compare(last) < 0; i--)
        records[i+1] = records[i];

    records[i+1].last = last;
    records[i+1].first = first;
    records[i+1].phone = num;

    l++;
}

void OrderedArrayList :: remove(string key)
{
    if( l == 0)
        return;

    int pos = search(key);
    if(pos == -1)
    {
        cout << "CANNOT FIND KEY" <<endl;
        return;
    }

    int i;
    for(i = pos; i < l; i++)
        records[i] = records[i+1];

    l--;
}

void OrderedArrayList :: clear()
{
    l = 0;
}

bool OrderedArrayList :: isFull() const
{
    return l == CAP - 1;
}

bool OrderedArrayList :: isEmpty() const
{
    return l == 0;
}

int OrderedArrayList :: search(string key) const
{
    int left = 0, right = l - 1, middle;

    while ( left <= right )
    {
        middle = ( left + right ) / 2;

        if ( records[middle].last.compare(key) == 0 || records[middle].first.compare(key) == 0 || records[middle].phone.compare(key) == 0 )
            return middle;
        else if ((records[middle].last).compare(key) < 0 )
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;

}

int OrderedArrayList :: length() const
{
    return l;
}

void OrderedArrayList :: print() const
{
    if(l == 0)
    {
        cout << "EMPTY LIST!!" << endl;
        return;
    }

    for(int i = 0; i < l; i++)
    {
        cout << records[i].last << setw(12)
             << records[i].first << setw(15)
             << records[i].phone << endl;
    }
}
#endif // ORDEREDARRAYLIST_H_INCLUDED
