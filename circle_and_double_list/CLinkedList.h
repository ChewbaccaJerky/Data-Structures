#ifndef CLINKEDLIST_H_INCLUDED
#define CLINKEDLIST_H_INCLUDED

#include <iostream>
#include "List.h"
using namespace std;

class CLinkedList
{
    private:
        struct Node
        {
            int v;
            Node* next;
        } *head, *cur, *las;
        int len;
    public:
    CLinkedList();
    CLinkedList(const CLinkedList &g);
    //overloaded operators
    CLinkedList& operator=(const CLinkedList &g);
    bool operator==(const CLinkedList &g);
    bool operator<(const CLinkedList &g);
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

};

#endif // CLINKEDLIST_H_INCLUDED

CLinkedList :: CLinkedList()
{
    head = cur = las = NULL;

    len = 0;
}

CLinkedList :: CLinkedList(const CLinkedList& g)
{
    this->head = g.head;
    this->len = g.len;
}

CLinkedList& CLinkedList :: operator=(const CLinkedList& g)
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

bool CLinkedList :: operator<(const CLinkedList& g)
{
    return getLength() < g.getLength();
}

bool CLinkedList :: operator==(const CLinkedList& g)
{
    return getLength() == g.getLength();
}

bool CLinkedList :: isFull() const
{
    return false;
}

bool CLinkedList :: isEmpty() const
{
    return head == NULL;
}

int CLinkedList :: getLength() const
{
    return len;
}

void CLinkedList :: print() const
{
    Node* p = head;
    cout << "FRONT-> ";
    while(p)
    {
        cout << p->v << "-> ";
        p = p->next;
        if(head == p)
        {
            cout << "FRONT" << endl;
            return;
        }
    }

}

void CLinkedList :: reset()
{
    cur = head;
}

void CLinkedList :: clear()
{
    Node* p = head;
    Node* front = head;
    while(p)
    {
        p = head;
        head = head->next;
        delete p;
        if(head == front)
        {
            head = las = NULL;
        }
    }
}

bool CLinkedList :: find(int key) const
{

    Node* front = head;
    Node* p = head;
    while(p)
    {
        if(p->v == key)
            return true;

        p = p->next;

        if(p == front)
            break;
    }

    return false;

}

int CLinkedList :: insert(int key)
{
    Node* n = new Node;
    n->v = key;
    //if creating node failed
    if(!n)
        return -1;

    //empty list
    if(isEmpty())
    {
        n->next = head = cur = las = n;
        len++;
        return 0;
    }

    //front?
    if(n->v < head->v)
    {
        n->next = head;
        head = n;
        las->next = head;
        len++;
        return 0;
    }

    //otherwise
    Node* p = head->next, *q = head;

    while(p != head && p->v < key)
    {
        p = p->next;
        q = q->next;
    }

    n->next = p;
    q->next = n;

    if(p == head)
        las = n;

    len++;
    return 0;
}

int CLinkedList :: remove(int key)
{
    if(isEmpty())
        return -1;

    Node* p = NULL;
    Node* front = head;

    if(head->v == key)
    {
        p = head;
        head = head->next;

        if(head == front)
            head = cur = las = NULL;
        else
        {
            las->next = head;
            if(cur == p)
                cur = cur->next;
        }
        delete p;
        len--;

    }

    Node* q = head;
    p = head->next;
    while(p && p->v != key)
    {
        p = p->next;
        q = q->next;
    }

    if(p != head)
    {
        if(p == cur )
            cur = p->next;
        if(p == las)
            las = las->next;

        q->next = p->next;
        delete p;
        len--;
    }
    return 0;
}

int CLinkedList :: getNext(int& val)
{
    if(isEmpty())
        return -1;

    val = cur->v;
    cur = cur->next;

    return 0;
}


