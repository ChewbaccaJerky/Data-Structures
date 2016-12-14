#include <iostream>
#include "PQueue.h"

using namespace std;

int main()
{
     PQueue p;

    p.insert(5);
    p.insert(10);
    p.insert(22);
    p.insert(3);

    int x;

    p.remove(x);
    cout << x << endl;          // should be 22.
    p.remove(x);
    cout << x << endl;          // should be 10

    cout << p.isEmpty();        // should be 0

    return 0;
}
