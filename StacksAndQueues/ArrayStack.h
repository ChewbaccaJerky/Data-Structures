#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED

#include <iostream>
#include "Stack.h"
using namespace std;

const int CAP = 10;

template < class T >
class ArrayStack : public Stack<T>
{
    private:
        T *stack;
        int t;
    public:
        ArrayStack();
        ~ArrayStack();
        int push( T );
        int pop( T& );
        int top( T& ) const;	// returns top value through parameter
        bool isFull() const;
        bool isEmpty() const;
};

template <class T>
ArrayStack<T> :: ArrayStack()
{
    stack = new T[CAP];
    t = -1;

}

template <class T>
ArrayStack<T> :: ~ArrayStack()
{
    delete stack;
}

template <class T>
int ArrayStack<T> :: push( T num)
{
    if(isFull())
        return -1;

    t++;
    stack[t] = num;
    return 0;
}

template <class T>
int ArrayStack<T> :: pop( T& num )
{
    if(isEmpty())
    {
        num = -1;
        return -1;
    }

    num = stack[t];
    t--;
    return 0;
}

template <class T>
int ArrayStack<T> :: top( T& num ) const
{
    if(isEmpty())
        return -1;

    num = stack[t];
    return 0;
}

template <class T >
bool ArrayStack<T> :: isFull() const
{
    return t == CAP-1;
}

template <class T>
bool ArrayStack<T> :: isEmpty() const
{
    return t == -1;
}

#endif // ARRAYSTACK_H_INCLUDED
