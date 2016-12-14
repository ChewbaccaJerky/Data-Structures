#ifndef ARRAYQUEUE_H_INCLUDED
#define ARRAYQUEUE_H_INCLUDED

#include <iostream>
#include "Queue.h"
using namespace std;


const int LIM = 10;
template <class T>
class ArrayQueue : Queue<T>
{
    private:
        T *Q;
        int f,b,len;
    public:
        ArrayQueue();
        ~ArrayQueue();
    // e & dequeue return 0 if successful, -1 otherwise
    int enqueue( T );
    int dequeue( T&);
	void makeEmpty();			// empties the queue.
    bool isEmpty() const;
    bool isFull() const;
};

template <class T>
ArrayQueue<T> :: ArrayQueue()
{
    Q = new T[LIM];
    f = b = len = 0;
}

template <class T>
ArrayQueue<T> :: ~ArrayQueue()
{
    delete Q;
}

template <class T>
int ArrayQueue<T> :: enqueue(T val)
{
    if(isFull())
        return -1;

    Q[b] = val;
    b++;


    if(b == LIM)
        b = 0;

    len++;


    return 0;
}

template <class T>
int ArrayQueue<T> :: dequeue(T& val)
{
    if(isEmpty())
    {
        cout << "here";
        return -1;
    }


    val = Q[f];
    f++;

    if(f == LIM)
        f = 0;

    len--;

    return 0;
}

template <class T>
void ArrayQueue<T> :: makeEmpty()
{
    f = b = len = 0;
}

template <class T>
bool ArrayQueue<T> :: isEmpty() const
{
    return len == 0;
}

template <class T>
bool ArrayQueue<T> :: isFull() const
{
    return len == LIM;
}
#endif // ARRAYQUEUE_H_INCLUDED
