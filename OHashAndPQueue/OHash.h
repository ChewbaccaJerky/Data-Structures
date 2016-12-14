#ifndef OHASH_H_INCLUDED
#define OHASH_H_INCLUDED

#include <iostream>
#include <string>
#include "Hash.h"
using namespace std;

const int SIZE = 10;

class OHash : public Hash
{
    protected:
    struct Node
    {
        string key;
        Node* next;
    }*head[SIZE];

    // the hash function accepts the key string and returns the index of the
    // corresponding element.
    int hash( string ) const;

    public:
    OHash();
    // inserts a key into the hash table. Returns 0 if successful, -1 otherwise
    int insert( string );
    // removes a key from the hash table. Returns 0 if successful, -1 otherwise
    int remove( string );
    // search for the key in the hash table. Returns true if found,
    //      false otherwise
    bool search( string ) const;
    // returns true if the hash table is full.
    bool isFull() const;
    //returns true if the hash table is empty
    bool isEmpty() const;
    // displays the contents of the hash table to the screen
    void print() const;
    // clears the hash table
    void clear();

};

OHash :: OHash()
{
    //sets each haed pointer to NULL
    for(int i = 0; i < SIZE; i++)
        head[i] = NULL;
}

int OHash :: hash(string key) const
{
    int sum = 0;
    char* cstr = new char[key.length()+1];
    strcpy(cstr, key.c_str());

    for(unsigned int i = 0; i < key.length(); i++)
        sum = cstr[i] - 64;                //64 ascii value before A

    return sum%10;
}
int OHash :: insert(string s)
{
    //sets where to place string
    int slot = hash(s);
    Node *n = new Node;
    n->key = s;
    n->next = NULL;

    //if empty
    if(head[slot] == NULL)
    {
        head[slot] = n;
        return 0;
    }

    //if not null, use p to traverse
    Node *p = head[slot];
    while(p->next)
        p = p->next;

    p->next = n;
    return 0;
}

bool OHash :: isEmpty() const
{
    int i;
    while(i <SIZE)
    {
        if(head[i] != NULL)
            return 0;
        i++;
    }
    return 1;
}

bool OHash :: isFull() const
{
    return false;
}

int OHash :: remove(string key)
{
    int slot = hash(key);

    //if that head pionter is empty
    if(head[slot] == NULL)
        return 0;

    Node* p;

    //case 1 front
    if(head[slot]->key == key)
    {
        p = head[slot];
        head[slot] = p->next;
        delete p;
        return 1;
    }

    //everything else
    Node* q = head[slot];
    p = head[slot]->next;

    while(p != NULL && p->key != key)
    {
        p = p->next;
        q = q->next;
    }

    // checks if it's at the end
    if(p->next)
    {
        q->next = p->next;
    }

    delete p;
    return 1;
}

bool OHash :: search(string key) const
{
    int slot = hash(key);

    //if is empty
    if(head[slot] == NULL)
        return false;

    Node* p = head[slot];

    while(p)
    {
        if(p->key == key)
            return true;
    }

    return false;
}

void OHash :: print() const
{
    Node* p;

    for(int i = 0; i < SIZE; i++)
    {
        p = head[i];
        while(p)
        {
            cout << p->key << " ";
            p = p->next;
        }
    }
    cout << endl;
}

void OHash :: clear()
{
    Node* p;

    for(int i = 0; i < SIZE; i++)
    {
        do
        {
            p = head[i];
            head[i] = p->next;
            delete p;
            p = head[i];
        }while(p);
    }
}




#endif // OHASH_H_INCLUDED
