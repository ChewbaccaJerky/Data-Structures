/*
	This file is missing key pieces to get your class working.
	It's up to you to flesh out the class with the necessary
	implementation details.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <String>
#include <iostream>
using std::cout;
using std::endl;

template< class T >
class LinkedList : public List<T>
{
	private:
	struct Node
    {
        T val;
        Node* next;
    } *head;
    int iteration,length;

	public:
	LinkedList();
	~LinkedList();
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
LinkedList<T>::LinkedList()
{
    head = NULL;
    iteration = 0;
    length = 0;
}

template< class T >
LinkedList<T>::~LinkedList()
{
}

template< class T >
void LinkedList<T>::append( T i )
{
    Node *p = new Node;

    p->val = i;             //set value

    p->next = NULL;         //set to null since it's going at the end

    if(!head)               //case 1:empty list
    {
        head = p;
        length++;
        return;
    }

    Node *temp = head;      //case 2:traverse list to the end
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = p;         //when reaching to the end have temp point to the new node;
    length++;
}

template< class T >
void LinkedList<T>::remove( T i )
{
    Node *p = NULL;
    Node *q = NULL;
    //if empty
    if(head == NULL)
        return;


    //first node
    if(head->val == i)
    {
        p = head;
        head = head->next;
        delete p;
        length--;
        return;
    }


    //set connect q and p-next then delete
    //search and remove;
    for(q = head, p=head->next;(p != NULL) && (p->val != i) ;q = q->next, p = p->next);

    if(p)
    {
        q->next = q->next->next;
        length--;
        delete p;
    }
}

template< class T >
void LinkedList<T>::clear()
{
    Node *temp = NULL;
    //check if empty
    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template< class T >
void LinkedList<T>::reset()
{
    iteration = 0;
}

template< class T >
T LinkedList<T>::getNext()
{
    Node *temp;
    int current = 0;
    // case 1:empty list
    if(!head)
        return -1;

    // case 2: traverse depending on iteration and checks if it is at the end  and get next.
    temp = head;

    while(current < iteration && temp->next)
    {
            temp = temp->next;
            current++;
    }

    iteration++;
    return temp->val;
}

template< class T >
int LinkedList<T>::getLength() const
{
    return length;
}

template< class T >
bool LinkedList<T>::isFull() const
{
    return false;
}

template< class T >
bool LinkedList<T>::isEmpty() const
{
    if(!head)
        return true;

    return false;
}

template< class T >
void LinkedList<T>::print() const
{
    //case 1: empty list
    if(!head)
    {
        cout << "HEAD->NULL\n";
        return;
    }

    //case 2:traverse and print;
    Node *temp;
    temp = head;

    cout << "head->";
    while(temp)
    {
        cout << " " << temp->val << "->";
        temp = temp->next;
    }
    cout << " NULL\n";
}

template< class T >
T LinkedList<T>::retrieve( int i) const
{
    Node *temp;
    temp = head;

    //empty list
    if(!temp)
        throw "Empty List Exception!";
    //traverse list
        for(int j = 0;j < i;j++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                throw "OUT OF BOUNDS!";
            }
        }

     if(temp)
        return temp->val;

    return 0;
}
#endif
