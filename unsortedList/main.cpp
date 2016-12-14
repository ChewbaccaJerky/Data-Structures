#include <iostream>

#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;

int main()
{
   LinkedList<int> l;
	ArrayList<double>a;

	for ( int i = 0; i < 10; i++ )
		l.append(i);

	l.remove(0);

    l.print();

	l.reset();

	cout << l.getNext() << endl;
    cout << l.getNext() << endl;
    l.print();

	cout << l.getLength() << endl;
    l.clear();
	l.print();

	cout << l.isEmpty() << endl;
	a.append( 22.5 );
	a.print();

    return 0;
}
