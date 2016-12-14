#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Queue
{
    public:
    // enqueue & dequeue return 0 if successful, -1 otherwise
    virtual int enqueue( T ) = 0;
    virtual int dequeue( T&) = 0;
	virtual void makeEmpty() = 0;			// empties the queue.
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif // QUEUE_H_INCLUDED
