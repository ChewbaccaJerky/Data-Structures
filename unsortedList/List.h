#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template< class T>
class List
{
    public:
    /* transformers/mutators */
    virtual void append( T ) = 0;      // appends new item into the list
    virtual void remove( T ) = 0;      // removes an item from the list
    virtual void clear() = 0;          // clears/destroys the list
    virtual void reset() = 0;          // resets iteration
    virtual T getNext() = 0;           // retrieves next item in the list,
                                       //    iteration. throws string literal
                                       //    exception, if list empty

    /* observers/accessors */
    virtual int getLength() const = 0; // returns number of items in the list
    virtual bool isFull() const = 0;   // returns true if list full, else false
    virtual bool isEmpty() const = 0;  // returns true if list empty, else false
    virtual void print() const = 0;    // displays the list on a single line
    virtual T retrieve(int) const = 0; // retrieves a value from the int'th
                                       //    position in the list, throws
                                       //    string literal exception, if out
                                       //    of bounds
};

#endif // LIST_H_INCLUDED
