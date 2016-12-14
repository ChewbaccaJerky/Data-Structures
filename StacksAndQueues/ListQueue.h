#ifndef LISTQUEUE_H_INCLUDED
#define LISTQUEUE_H_INCLUDED

#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
class ListQueue : public Queue<T>
{
    private:
        struct Node
        {
            T v;
            Node* next;
        } *FR,*BK;

    public:
        ListQueue();
    // enqueue & dequeue return 0 if successful, -1 otherwise
    int enqueue( T );
    int dequeue( T&);
	void makeEmpty();			// empties the queue.
    bool isEmpty() const;
    bool isFull() const;

};

template <class T>
ListQueue<T> :: ListQueue()
{
        FR = NULL;
        BK = NULL;
}

template <class T>
int ListQueue<T> :: enqueue(T val)
{
    if(isFull())
        return -1;

    Node* n = new Node;
    n->v = val;
    n->next = NULL;

    if(isEmpty())
    {
        FR = n;
        BK = n;
        return 0;
    }

    BK->next = n;
    BK = n;

    return 0;
}

template <class T>
int ListQueue<T> :: dequeue(T& val)
{
    if(isEmpty())
        return -1;

    val = FR->v;

    Node* temp = FR;

    FR = FR->next;
    delete temp;

    if(isEmpty())
        BK = NULL;

    return 0;
}

template <class T>
void ListQueue<T> :: makeEmpty()
{
    Node *temp;

    while(FR != NULL)
    {
        temp = FR;
        FR = FR->next;
        delete temp;
    }
}

template <class T>
bool ListQueue<T> :: isFull() const
{
    return false;
}

template <class T>
bool ListQueue<T> :: isEmpty() const
{
    return FR == NULL;
}
#endif // LISTQUEUE_H_INCLUDED
