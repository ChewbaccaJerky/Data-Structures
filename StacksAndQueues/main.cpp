#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "ArrayQueue.h"
#include "ArrayStack.h"
#include "ListQueue.h"
#include "ListStack.h"

int main (int argc, char const* argv[])
{
    ArrayQueue<int> aq;
    ArrayStack<int> as;
    ListQueue<int> lq;
    ListStack<int> ls;

    int i, j;
    cout << "ARRAY QUEUE:" << endl;
    for ( i = 0; i < 5; i++ )
        aq.enqueue(i);

    for ( i = 0; i < 5; i++ )
    {
        aq.dequeue(j);
        cout << j << " ";
    }

    cout << endl;

    for ( i = 0; i < 10; i++ )
        aq.enqueue(i);

    while ( !aq.isEmpty() )
    {
        aq.dequeue(j);
        cout << j << " ";
    }

    cout << endl;
    cout << "ARRAY STACK:" << endl;
    for ( i = 0; !as.isFull(); i++ )
        as.push(i);

    while ( !as.isEmpty() )
    {
        as.pop(j);
        cout << j << " ";
    }

    cout << endl;
    cout << "LIST QUEUE:" << endl;
    for ( i = 0; i < 5; i++ )
         lq.enqueue(i);

    while ( !lq.isEmpty() )
    {
        lq.dequeue(j);
        cout << j << " ";
    }

    cout << endl;
    cout << "LIST STACK:" << endl;

    for ( i = 0; i < 5; i++ )
        ls.push(i);


    while( !ls.isEmpty() )
    {
        ls.pop(j);
        cout << j << " ";
    }


    cout << endl;
    cout << endl;

    return 0;
}
