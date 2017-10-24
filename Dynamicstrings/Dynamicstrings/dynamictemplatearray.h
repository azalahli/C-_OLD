/* Myron Pow, CS_2B_A7, Dave Harden, 7/25/2015
We're reimplementing list and vectors.
Inputs are arrays of int or strings.
This particular implementation is horribly incomplete
I would like to say that vstudio has template source code 
sorcery
*/
/*CLASS INFORMATION
This class is a templated version of programming assignment 10.6, 
intended to extend the functionalities to int types as well as strings
DATA MEMBERS:
    T * custArray;
Stores the array of the template

    int arraySize;
Stores the size of the array

Pre: None
    DynamicTemplateArray();
Post: Default array of null, size 0

pre, object of the dynamic array type
    DynamicTemplateArray(const DynamicTemplateArray<T> &list);
post, deepcopy of parameter list

pre two objects of type T
    void operator = (const T &rlist);
post, deepcopy of rlist

pre: none
    ~DynamicTemplateArray();
post none, frees memory

pre: none
    int getSize();
post returns the arraySize value

pre int index
    T getEntry(int findIndex);
post element at index

pre, elements of type T to be added
    T addEntry(T &element);
post, array, with element appended to back

pre, element to delete
    bool deleteEntry(T &element);
post, array with elements deleted and size changed;
*/


#ifndef dynamicarray
#define dynamicarray

#include <string>

namespace cs_2b_a7
{




template <class T>
class DynamicTemplateArray
{
private:
    T * custArray;
    int arraySize;
public:
    DynamicTemplateArray();
    DynamicTemplateArray(const DynamicTemplateArray<T> &list);
    void operator = (const T &rlist);
    ~DynamicTemplateArray();
    int getSize();
    T getEntry(int findIndex);
    T addEntry(T &element);
    bool deleteEntry(T &element);
};

}

#include "dynamictemplatearray.cpp"


#endif
