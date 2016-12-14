#ifndef LISTSTACK_H_INCLUDED
#define LISTSTACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

template < class T >
class ListStack : public Stack<T>
{
    private:
        struct Node
        {
            T v;
            Node* next;
        } *Top;

    public:
        ListStack();
        int push( T );
        int pop( T& );
        int top( T& ) const;	// returns top value through parameter
        bool isFull() const;
        bool isEmpty() const;
};

template <class T>
ListStack<T> :: ListStack()
{
    Top = NULL;
}

template <class T>
int ListStack<T> :: push( T num)
{
    if(isFull())
        return false;

    Node *n = new Node;
    n->v = num;

    if(isEmpty())
    {
        Top = n;
        n->next = NULL;
        return 0;
    }

    n->next = Top;
    Top = n;



    return 0;
}

template <class T>
int ListStack<T> :: pop( T& num )
{
    //case 1: empty list
    if(isEmpty())
    {
        return -1;
        cout << "here";
    }

    num = Top->v;

    Node* temp = Top;

    Top = Top->next;
    delete temp;

    return 0;
}

template <class T>
int ListStack<T> :: top( T& value ) const
{
    if(isEmpty())
        return -1;

    value = Top->v;
    return 0;
}

template <class T>
bool ListStack<T> :: isFull() const
{
    return false;
}

template <class T>
bool ListStack<T> :: isEmpty() const
{
    return Top == NULL;
}



#endif // LISTSTACK_H_INCLUDED
