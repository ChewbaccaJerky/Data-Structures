/*
    Here is what a test driver *could* look like.  I'm not going
    to include every single test case I could think of because
    that would be overkill.  However, any test cases I use
    to grade your assignment would be similar to these.

    Any test plan I implement would be similar to this one.

    Remember, I may grade any one of your solutions at random.
    I will not grade all of them.

    Write each of your methods as if I were to test them
    individually similar to what you see here.

    This MAY NOT BE the test plan I use on your submission!
*/

#include "OrderedLinkedList.h"

int main()
{
    OrderedLinkedList oll;

    // Test 1: Insert 3 records into the list
    oll.insert("Doe", "John", "555-1234" );
    oll.insert("Jones", "Jim", "555-1235" );
    oll.insert("Branson", "Richard", "555-1236");

    // Test 2:  Print List
    /* Expected output the records in order, for example:
        Branson, Richard, 555-1236
        Doe, John, 555-1234
        Jones, Jim, 555-1235
    */
    oll.print();

    // Test 3:  length.  Expected output:  3
    cout << oll.length() << endl;

    // Test 4:  isEmpty. Expected output: false
    cout << oll.isEmpty() << endl;

    // Test 5:  Search for Jim Jones. Expected output, 2
    cout << oll.search("Jones") << endl;

    // Test 6:  Remove John Doe, the print list.
    // expected output: something like:
    /*  Branson, Richard, 555-1236
        Jones, Jim, 555-1235    */
    oll.remove("Doe");
    oll.print();

    // Test 7:  clear() the list destroys the list, then print().
    // expected output:  nothing.  List is empty.
    oll.clear();
    oll.print();

    // Test 8: isFull() - expected result:  false.
    cout << oll.isFull() << endl;

    // Test 9: isEmpty() - expected result: true.
    cout << oll.isEmpty() << endl;


    return 0;
}
