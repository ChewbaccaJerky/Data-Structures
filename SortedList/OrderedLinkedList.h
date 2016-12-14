#ifndef ORDEREDLINKEDLIST_H_INCLUDED
#define ORDEREDLINKEDLIST_H_INCLUDED

#include <iostream> //std::cout, std::endl
#include <string>   //string
#include <iomanip>  //std::setw
#include "List.h"

using namespace std;

class OrderedLinkedList : public List
{
    private:
        Record *head;
        int l;          //length
    public:
        OrderedLinkedList();
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

OrderedLinkedList :: OrderedLinkedList()
{
        head = NULL;
        l = 0;
}

void OrderedLinkedList :: insert( string last, string first, string num)
{
    Record *r = new Record;
    r->last = last;
    r->first = first;
    r->phone = num;

    //case 0: empty;
    if( l == 0 )
    {
        head = r;
        r->next = NULL;
        l++;
        return;
    }

    //case 1: front?
    if(r->last.compare(head->last) < 0)
    {
        r->next = head;
        head = r;
        l++;
        return;
    }

    //case 2: search the rest of the array
    Record *p, *q;
    for(q = head, p = head->next; p != NULL && p->last.compare(r->last) < 0; q = q->next, p = p->next);

    r->next = p;
    q->next = r;
    l++;
    return;
}

void OrderedLinkedList :: remove( string key)
{
    // case 0: empty list
    if( l == 0)
        return;

    //case 1: first record
    Record *p = NULL;
    if( head->last.compare(key) == 0)
    {
        p = head;
        head = head->next;
        delete p;
        l--;
        return;
    }

    //case 2: search and destroy
    Record *q = NULL;
    for(q = head, p = head->next;p != NULL && p->last.compare(key) != 0; q = q->next, p = p->next);

    if(p != NULL)
    {
        q->next = p->next;
        delete p;
        l--;
    }
}

void OrderedLinkedList :: clear()
{
    Record* p = NULL;

	while ( head->next != NULL )
	{
		p = head;
		head = head->next;
		delete p;
	}
	l = 0;
}

bool OrderedLinkedList :: isFull() const
{
    return false;
}

bool OrderedLinkedList :: isEmpty() const
{
    return l == 0;
}

int OrderedLinkedList :: search( string key) const
{
    Record *p;
    int pos = -1;
    p = head;

    while(p != NULL)
    {
        pos++;

        if(p->last.compare(key) == 0)
            return pos;
        else if(p->first.compare(key) == 0)
            return pos;
        else if(p->phone.compare(key) == 0)
            return pos;

        p = p->next;
    }
    return pos;
}

int OrderedLinkedList :: length() const
{
    return l;
}

void OrderedLinkedList :: print() const
{
    Record *p;

    //case 1: empty
    if( l == 0 )
    {
        cout << "EMPTY LIST!!";
        return;
    }

    //case 2: everything else
    p = head;
    while(p)
    {
        cout << p->last << setw(10)
             << p->first << setw(14)
             << p->phone << endl;
        p = p->next;
    }
}
#endif // ORDEREDLINKEDLIST_H_INCLUDED
