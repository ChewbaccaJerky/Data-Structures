#ifndef LINKEDBST_H_INCLUDED
#define LINKEDBST_H_INCLUDED
#include "LBST.h"
#include <iostream>
class LinkedBST : public LBST
{
    protected:

    // private, helper methods.
    void inprint( Node* r ) const       // recursively displays tree inorder
    {
        if ( r == NULL )
            return;

        inprint( r->left );
        cout << r->key << " ";
        inprint( r->right );
    }
    void preprint( Node* r) const   // recursively displays tree preorder
    {
        if( r == NULL)
            return;

        cout << r->key << " ";
        preprint( r->left);
        preprint( r->right);
    }
    void postprint( Node* r ) const  // recursively displays tree postorder
    {
        if( r == NULL)
            return;

        postprint( r->left);
        postprint( r->right);
        cout << r->key << " ";
    }
    void insert( Node*&, char );     // recursively inserts a node
    bool search( Node*, char ) const; // recursively finds a node
    void seek( Node*&, char );      // searches for node to destroy, then
    void destroy( Node*& );         // calls this to destroys a node
    void delTree( Node*& );         // destroys tree, call in destructor

    public:
    LinkedBST();
    ~LinkedBST();
    // public interface methods call the private helper methods.
    // I've done inprint() to get you started.
    void inprint() const            // displays tree using inorder traversal
    {
        inprint( root );
        cout << endl;
    }

    void preprint() const      // calls preprint( Node* )
    {
        preprint( root );

        cout << endl;
    }
    void postprint() const     // calls postprint( Node* )
    {
        postprint( root );
        cout << endl;
    }
    void insert( char key)        // calls insert( Node*&, char )
    { insert(root, key); }
    void seek( char key)          // calls seek( Node*&, char )
    {   seek(root, key); }
    bool search( char key ) const  // calls search( Node*, char )
    {   return search(root,key); }
    bool isEmpty() const       // empty=true, otherwise false
    { return root == NULL;}

};

LinkedBST :: LinkedBST()
{   root = NULL; }

LinkedBST :: ~LinkedBST()
{ delTree(root); }
void LinkedBST :: insert(Node*& r, char key)
{
    Node* p = r;

    //case 1 empty
    if(p == NULL)
    {
        Node* n = new Node;
        n->key = key;
        n->left = NULL;
        n->right = NULL;
        r = n;
        return;
    }
    else if(key < p->key)
        insert(p->left, key);
    else
        insert(p->right, key);
}

void LinkedBST :: seek(Node*& r, char key)
{
    Node*p = r;
    if(p == NULL)
        return;

    if(p->key == key)
        destroy(p);
    else if(key < p->key)
        seek(p->left,key);
    else
        seek(p->right,key);
}

void LinkedBST :: destroy( Node*& r)
{
    Node* p = NULL;
    //no children
    if(r->left == NULL && r->right == NULL)
    {
        delete r;
        r = NULL;
    }
    else if(r->left && !r->right)
    {
        p = r;
        r = r->left;
        delete p;
    }
    else if(!r->left && r->right)
    {
        p = r;
        r = r->right;
        delete p;
    }
    else
    {

        p = r->right;

        while(p->left != NULL)
            p = p->left;

        r->key = p->key;
        r->right = NULL;
        delete p;

    }
}

bool LinkedBST :: search(Node* r, char key) const
{
    Node* p = r;

    if(p == NULL)
        return false;
    else if(p->key == key)
        return true;
    else if(key < p->key)
        search(p->left,key);
    else
        search(p->right,key);

}

void LinkedBST :: delTree(Node*& r)
{
    if(r == NULL)
        return;

    delTree(r->left);
    delTree(r->right);
    delete r;
}



#endif // LINKEDBST_H_INCLUDED
