#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template < class T >
class Stack
{
    public:
    // push, pop, top return 0 if successful, -1 otherwise.
    virtual int push( T ) = 0;
    virtual int pop( T& ) = 0;
    virtual int top( T& ) const = 0;	// returns top value through parameter
	virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;


};

#endif // STACK_H_INCLUDED
