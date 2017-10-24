/* Myron Pow, CS_2B_A7, Dave Harden, 7/25/2015
We're reimplementing list and vectors.
This is the partial implementation file as of 11:30
Not conversion, a dry template run
*/

/*
    T * custArray;
Stores the array of type T

    int arraySize;
Stores the size of the array of type T

There is little that will hold true for all objects
of this template
*/

//#include "dynamicTemplateArray.h"
#include <cassert>
using namespace std;


namespace cs_2b_a7
{




//Default Constructor
template <class T>
DynamicTemplateArray<T>::DynamicTemplateArray()
{
    custArray = NULL;
    arraySize = 0;
}




//Returns size of array
template <class T>
int DynamicTemplateArray<T>::getSize()
{
    return arraySize;
}





//Overloaded assignment operator
template <class T>
void DynamicTemplateArray<T>::operator = (const T &rlist)
{
    custArray = new T[(rlist.getSize()+1)];
    for (int k = 0; k < (rlist.getSize()+1); k++)
        custArray[k] = rlist[k];
}





//Copy Constuctor
template <class T>
DynamicTemplateArray<T>::DynamicTemplateArray (const DynamicTemplateArray<T> &list)
{
    this = list;
}





//Destuctor
template <class T>
DynamicTemplateArray<T>::~DynamicTemplateArray()
{
    delete [] custArray;
    arraySize = 0;
}




//gets an entry at an index
//Could be done with overloaded brackets?
template <class T>
T DynamicTemplateArray<T>::getEntry(int index)
{
    assert (index >= 0 && index < getSize());
    return custArray[index];
}




//Appends an array to the back of the calling object
template <class T>
T DynamicTemplateArray<T>::addEntry(T &addition)
{
    int oriSize = arraySize + 1;
    arraySize += addition.getSize();
    for (int k = 0; k < (arraySize - addition.getSize()), k++)
    {
        custArray[(oriSize + k)] = addition[k];
    }
    return this;
}





//Deletes all instances of the element in the array
template <class T>
bool DynamicTemplateArray<T>::deleteEntry (T &element)
{
    int sizeDecrease = 0;
    for (int k = 0; k < arraySize; k++)
    {
        if (element == custArray[k])
        {
            custArray[k] = custArray[(k+1)];
            sizeDecrease++;
        }
    }
    arraySize -= sizeDecrease;
    return (sizeDecrease == 0);
}



}