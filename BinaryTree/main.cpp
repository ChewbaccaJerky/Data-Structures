#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "LinkedBST.h"

int main (int argc, char const* argv[])
{
    LinkedBST l;

    // let's build the tree...
    l.insert('G');
    l.insert('E');
    l.insert('L');
    l.insert('A');
    l.insert('F');
    l.insert('H');
    l.insert('O');

    // let's see it - should display the tree in this order:
    l.preprint();                   //  G, E, A, F, L, H , O

    // let's remove a node
    l.seek('E');

    // let's see the changes
    l.preprint();                   // G, F, A, L, H, O

    // let's search for a key:
    cout << l.search('H') << endl;  // should display 1.

    // check if it's empty
    cout << l.isEmpty() << endl;    // should display 0.

    return 0;
}
