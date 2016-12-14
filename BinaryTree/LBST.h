#ifndef LBST_H_INCLUDED
#define LBST_H_INCLUDED

#include <iostream>
using namespace std;

class LBST
{
    protected:

    struct Node
    {
        char key;
        Node* left, *right;
    } *root;

    // private, helper methods.
    void inprint( Node* r ) const       // recursively displays tree inorder
    {
        if ( r == NULL )
            return;

        inprint( r->left );
        cout << r->key << " ";
        inprint( r->right );
    }

    virtual void preprint( Node* ) const = 0;   // recursively displays tree preorder
    virtual void postprint( Node* ) const = 0;  // recursively displays tree postorder
    virtual void insert( Node*& , char ) = 0;     // recursively inserts a node
    virtual bool search( Node*, char ) const = 0; // recursively finds a node
    virtual void seek( Node*&, char ) = 0;      // searches for node to destroy, then
    virtual void destroy( Node*& ) = 0;         // calls this to destroys a node
    virtual void delTree( Node*& ) = 0;         // destroys tree, call in destructor

    public:
    // public interface methods call the private helper methods.
    // I've done inprint() to get you started.
    virtual void inprint() const            // displays tree using inorder traversal
    {
        inprint( root );
        cout << endl;
    }

    virtual void preprint() const = 0;      // calls preprint( Node* )
    virtual void postprint() const = 0;     // calls postprint( Node* )
    virtual void insert( char ) = 0;        // calls insert( Node*&, char )
    virtual void seek( char ) = 0;          // calls seek( Node*&, char )
    virtual bool search( char ) const = 0;  // calls search( Node*, char )
    virtual bool isEmpty() const = 0;       // empty=true, otherwise false
};


#endif // LBST_H_INCLUDED
