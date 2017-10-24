// ConsoleApplication41.cpp : Defines the entry point for the console application.
//

#include "linkedlist.h"
#include <iostream>
using namespace cs2b_linkedlist;


int main()
{
    linkedList<int> intList;
    intList.addEntry(2);
    intList.addEntry(3);
    intList.addEntry(4);
    cout << intList.getSize();
    cout << endl;
    intList.deleteEntry(2);
    cout << intList.getEntry(0);
    cout << intList.getEntry(1);
    //cout << intList.getEntry(2);
    cout << "b1" << endl;

    linkedList<int> intPls(intList);
    cout << "b2" << endl;
    linkedList<int> hello;
    cout << "b3" << endl;
    hello = intList;
    cout << "b1" << endl;
    cout << endl;
    cout << endl;
    
    cout << intPls.getEntry(0);
    cout << intPls.getEntry(1);
    cout << intPls.getEntry(2);
    cout << endl << endl;
   
    cout << hello.getEntry(0);
    cout << hello.getEntry(1);
    cout << hello.getEntry(2);
    
}