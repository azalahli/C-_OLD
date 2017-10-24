/* Myron Pow, CS2B, 7/11/2015, Dave Harden, mystring.h
Program is an implementation of dynamic cstring(s).
No input is provided by a user, as it is preprepared in a client,
and the output is printed streams throughly after testing the class
*/
#include "mystring.h"
#include <iostream>
#include <cassert>
using namespace std;

/*
The order of my fuctions offends me
When doing next section sort them into categories :d
*/

namespace cs2b_mystring
{


//Precondition array of chars
//post number of chars as an int
int myString::length() const
{
    int x;
    x = strlen(name);
    return x;
}





//precond string to print
//postcond stream ready for printing
ostream &operator<<(ostream &out, myString str1)
{
    for (int i=0; i < str1.length(); i++)
    {
        out << str1[i];
    }
    return out;
}






//pre array of chars, index
//post char at position of index, constant
char myString::operator[](int id) const
{
    assert((id >= 0) && (id < strlen(name)));
    return name[id];
}





//pre array of chars, index
//post char at position of index, modifiable
char &myString::operator[](int id)
{
    assert((id >= 0) && (id < strlen(name)));
    return name[id];
}






//pre none(default constructor)
//post empty string
myString::myString()
{
    name = new char[1];
    strcpy(name, "");
}





//Pre cstring
//post string with the contents of the cstring
myString::myString(const char *cstr)
{
    name = new char[strlen(cstr)+1];
    strcpy(name, cstr);
}





//pre myString obj1
//post myString obj2 w/ contents of obj1
myString::myString(const myString &rhs)
{
    name = new char[strlen(rhs.name)+1];
    strcpy(name, rhs.name);
}



//Destructor
myString::~myString()
{
    delete [] name;
}



//Assignment operator
//pre myString str1, myString rhs
//post str1 is a deepcopy of rhs
myString myString::operator=(const myString &rhs)
{
    if (this != &rhs)
    {
        delete [] name;
        name =  new char[strlen(rhs.name)+1];
        strcpy(name, rhs.name);
    }
    return *this;
}




//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv <
bool operator<(const myString &lhs, const myString &rhs)
{
    return (strcmp(lhs.name, rhs.name) < 0);
}



//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv <=
bool operator<=(const myString &lhs, const myString &rhs)
{
    return (strcmp(lhs.name, rhs.name) <= 0);
}



//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv >
bool operator>(const myString &lhs, const myString &rhs)
{
    return (strcmp(lhs.name, rhs.name) > 0);
}




//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv >=
bool operator>=(const myString &lhs, const myString &rhs)
{
    return (strcmp(lhs.name, rhs.name) >= 0);
}




//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv ==
bool operator==(const myString &lhs, const myString &rhs)
{
    return (strcmp(lhs.name, rhs.name) == 0);
}





//Pre lhs is myString, rhs is myString, cstring
//Post bool result of comparison, eqiv !=
bool operator!=(const myString &lhs, const myString &rhs)
{
    return !(lhs == rhs);
}


}