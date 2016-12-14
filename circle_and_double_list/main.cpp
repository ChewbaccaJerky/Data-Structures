#include <iostream>
#include "DLinkedList.h"
#include "CLinkedList.h"
using namespace std;

int main()
{
    CLinkedList d;
    int v;

    for(int i =0; i < 10; i++)
        d.insert(i);


    d.print();

    for(int i =0; i < 10; i++)
    {
        d.getNext(v);
        cout << "Value " << i << ":" << v << endl;
    }

    d.reset();
    d.getNext(v);
    cout << "Value:" << v << endl;

    d.remove(8);
    d.print();

    if(d.find(3))
        cout << "FOUND IT!\n";


    d.print();
    cout << "Empty?\n";
    if(d.isEmpty())
        cout << "IT IS EMPTY!\n";
    else
        cout << "SOMETHINGS IN HERE\n";

    CLinkedList g = d;
    g.print();

    cout << (g<d) << endl;
    cout << d.getLength() << endl;
    cout << g.getLength() << endl;




    return 0;
}
