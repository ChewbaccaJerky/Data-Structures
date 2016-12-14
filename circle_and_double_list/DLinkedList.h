#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

#include <iostream>
#include "List.h"
using namespace std;

class DLinkedList : public List
{
    private:
        struct Node
        {
            int v;
            Node *prev,*next;
        } *head,*cur;
        int len, beginning;


    public:
    DLinkedList();
    //copy constructor
    DLinkedList(const DLinkedList &g);
    //overloaded operators
    DLinkedList& operator=(const DLinkedList &g);
    bool operator==(const DLinkedList &g);
    bool operator<(const DLinkedList &g);
    // inserts it's argument into the list. Returns 0 if successful,
    //  -1 otherwise.
    int insert( int );

    // removes the first record matching it's argument from the
    // list.  Returns 0 if successful, -1 otherwise.
    int remove( int );

    // searches the list for the first record matching it's argument.
    // returns true if found, false otherwise.
    bool find( int ) const;

    // returns true if the list is full, false otherwise
    bool isFull() const;

    // returns true if the list is empty, false otherwise
    bool isEmpty() const;

    // returns the current length of the list, as an integers
    int getLength() const;

    // returns the "next" value in the list through it's
    //   reference parameter. Returns 0 if successful, -1 other
    //   wise.  The first time getNext() is invoked, it should
    //   return the first item in the list.
    int getNext( int& );

    // resets the iterator to the first position in the list.
    void reset();

    // deletes/clears/destroys the list
    void clear();

    // displays the current list on a single line.
    void print() const;

    void rprint() const;
};

#endif // DLINKEDLIST_H_INCLUDED

DLinkedList :: DLinkedList()
{
    head = cur = NULL;
    len = 0;
    beginning = -1;
}

//copy constructor
DLinkedList :: DLinkedList(const DLinkedList& g)
{
    this->head = g.head;
    this->len = g.len;
}

//overloaded operators
DLinkedList& DLinkedList :: operator=(const DLinkedList &g)
{
    clear();
    Node* p = g.head;
    while(p)
    {
        insert(p->v);
        p = p->next;
    }
    return *this;
}

bool DLinkedList :: operator==(const DLinkedList &g)
{
    return getLength() == g.getLength();
}

bool DLinkedList :: operator<(const DLinkedList &g)
{
    return getLength() < g.getLength();
}

int DLinkedList :: insert(int val)
{
    Node* n = new Node;
    n->v = val;
    //out of memory

    //empty list
    if(isEmpty())
    {
        n->next = n->prev = NULL;
        head = cur = n;
        len++;
        return 0;
    }

    //front of list
    if(n->v < head->v)
    {
        n->next = head;
        n->prev = NULL;

        head->prev = n;
        head = n;
        len++;
        return 0;
    }

    //search and insert
    Node* q = head;
    Node* p = head->next;

    while(p && p->v < n->v)
    {
        p = p->next;
        q = q->next;
    }

    if(p)
        p->prev = n;

    n->next = p;
    n->prev = q;

    q->next = n;
    len++;
    return 0;
}

int DLinkedList :: remove(int val)
{
    if(isEmpty())
        return -1;

    if(find(val))       //checks if val exist
    {
        Node *p = head;
        //front of list
        if(head->v == val)
        {
            head = head->next;

            if(head)
                head->prev = NULL;

            delete p;
            len--;
            return 0;
        }

        p = head->next;

        while(p!=NULL && p->v != val)   //traverse list
            p = p->next;

        if(p)
        {
            if(p->next)
                p->next->prev = p->prev;

            p->prev->next = p->next;

            delete p;
            len--;
            return 0;
        }
    }
    return -1;
}

bool DLinkedList :: find(int val) const
{
    Node* p = head;
    int pos = 0;

    while(p)
    {
        if(p->v == val)
            return true;

        pos++;
        p = p->next;
    }
    return false;
}

bool DLinkedList :: isFull() const
{
    return false;
}

bool DLinkedList :: isEmpty() const
{
    return head == NULL;
}

int DLinkedList :: getLength() const
{
    return len;
}

int DLinkedList :: getNext(int &val)
{
    if(isEmpty())
        return -1;

    val = cur->v;
    cur = cur->next;

    //resets cur if it hits the end of the list
    if(!cur)
        cur = head;
    return 0;
}
void DLinkedList :: reset()
{
    cur = head;
    beginning = -1;
}

void DLinkedList :: clear()
{
    if(isEmpty())
        return;

    Node *p = NULL;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    len = 0;
}

void DLinkedList :: print() const
{
    Node *p = head;
    while(p)
    {
        cout << p->v << " ";
        p = p->next;
    }

    cout << endl;
}

void DLinkedList :: rprint() const
{
    if(isEmpty())
        return;

    Node* tail = head;

    while(tail->next)
        tail = tail->next;

    while(tail)
    {
        cout << tail->v << " ";
        tail = tail->prev;
    }

    cout << endl;
}
