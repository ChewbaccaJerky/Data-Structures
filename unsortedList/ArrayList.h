#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED
#include "List.h"

#include <iostream>
using std::cout;
using std::endl;

const int CAPACITY = 20;

template< class T >
class ArrayList : public List<T>
{
	private:
        int l,              //length of the list
            iteration;
        T *arrayList;

	public:
	ArrayList();
	~ArrayList();
	void append( T );
	void remove( T );
	void clear();
	void reset();
	T getNext();

	int getLength() const;
	bool isFull() const;
	bool isEmpty() const;
	void print() const;
	T retrieve ( int ) const;
};

template< class T >
ArrayList<T>::ArrayList()
{
    arrayList = new T[CAPACITY];
    l = 0;
}

template< class T >
ArrayList<T>::~ArrayList()
{
    delete arrayList;
}

template< class T >
void ArrayList<T>::append( T i )
{
    //case 1: full list
    if(l == CAPACITY)
        return;

    arrayList[l] = i;
    l++;
}

template< class T >
void ArrayList<T>::remove( T i )
{
    //case 1: empty list
    if(l == 0)
        return;
    //case 2: traverse and destroy
    int j;
    for(j = 0; l < CAPACITY && i != arrayList[j]; j++)

    j = j;
    if(i == arrayList[j])
    {
        // at the end;
        if(l == j-1)
        {
            l--;
            return;
        }
        // everything else
        for(j+1;j < l;j++)
        {
            arrayList[j] = arrayList[j+1];
        }
        l--;
    }


    return;



}

template< class T >
void ArrayList<T>::clear()
{
    l = 0;
}

template< class T >
void ArrayList<T>::reset()
{
    iteration = 0;
}

template< class T >
T ArrayList<T>::getNext()
{
    T val;
    val = arrayList[iteration];
    iteration++;
    return val;
}

template< class T >
int ArrayList<T>::getLength() const
{
    return l;
}

template< class T >
bool ArrayList<T>::isFull() const
{
    return CAPACITY == l;
}

template< class T >
bool ArrayList<T>::isEmpty() const
{
    return l == 0;
}

template< class T >
void ArrayList<T>::print() const
{
    cout << "head-> ";
    for(int i = 0;i<l;i++)
        cout << arrayList[i] << "-> ";
    cout << "NULL" << endl;
}

template< class T >
T ArrayList<T>::retrieve( int i) const
{
    if(i > l)
    {
        throw "OUT OF BOUNDS!!";
        return 0;
    }
    return arrayList[i];
}



#endif // ARRAYLIST_H_INCLUDED
