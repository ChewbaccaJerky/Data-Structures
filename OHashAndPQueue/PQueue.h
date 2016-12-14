#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED

#include <iostream>
#include "Heap.h"
using namespace std;

const int size = 30;

class PQueue : public Heap
{

    protected:
    int *Array;
    int len;
    void reheapup( int, int );      // helper functions for
    void reheapdown( int, int );    //  maintaining order of heap
    void swap(int, int);
    public:
    PQueue();
    ~PQueue();
    // adds a value to heap top - returns 0 if successfull, -1 otherwise
    int insert( int );
    // removes a value from heap top through reference parameter.  Returns 0
    //  if successful, -1 otherwise.
    int remove( int& );
    bool isEmpty() const;           // returns true if heap empty
    bool isFull() const;            // returns true if heap full
    void print() const;             // prints contents of heap
    void clear();		            // clears heap
    int dequeue();
    void enqueue(int);
};

PQueue :: PQueue()
{
    Array = new int[size];
    for(int i = 0; i < size; i++)
        Array[i] = -1;

    len = 0;
}

PQueue :: ~PQueue()
{
    delete Array;
}

bool PQueue :: isEmpty() const
{
    return len == 0;
}

bool PQueue :: isFull() const
{
    return len == size;
}

void PQueue :: clear()
{
    for(int i = 0; i < size; i++)
        Array[i] = -1;
}
//swaps a for b in the array
void PQueue :: swap(int a, int b)
{
    int temp = Array[a];
    Array[a] = Array[b];
    Array[b] = temp;
}

void PQueue :: reheapdown(int root,int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root*2+1;
    rightChild = root*2+2;
    if(leftChild <= bottom)
    {
        if(leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if(Array[leftChild] <= Array[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if(Array[root] < Array[maxChild])
        {
            swap(root, maxChild);
            reheapdown(maxChild,bottom);
        }
    }
}

void PQueue :: reheapup(int root, int bottom)
{
    int parent;
    if(bottom > root)
    {
        parent = (bottom-1)/2;
        if(Array[parent] < Array[bottom])
        {
            swap(bottom, parent);
            reheapup(root,parent);
        }
    }
}

int PQueue :: insert(int key)
{
    if(isFull())
        return -1;

    Array[len] = key;           //len always has the value of the next available spot

    if(Array[(len-1)/2] < key)
        reheapup((len-1)/2,len);

    len++;
    return 0;
}

int PQueue :: remove(int& val)
{
    if(isEmpty())
        return -1;

    val = Array[0];
    Array[0] = Array[len-1];
    Array[len-1] = -1;
    reheapdown(0,2);
    len--;

    return 0;
}

void PQueue :: print() const
{
    for(int i = 0; i< size; i++)
    {
        if(Array[i] != -1)
            cout << Array[i] << " ";
    }
    cout << endl;
}

int PQueue :: dequeue()
{
    if(isEmpty())
        return -1;

    int temp = Array[0];
    Array[0] = Array[len-1];
    Array[len-1] = -1;
    reheapdown(0,2);
    len--;
    return temp;
}
void PQueue :: enqueue(int key)
{
    if(isEmpty())
        return;

    int temp = Array[0];
    Array[0] = key;
    Array[len-1] = temp;
    len++;
}
#endif // PQUEUE_H_INCLUDED
