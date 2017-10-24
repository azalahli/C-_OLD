/* Myron Pow, CS2B, 7/18/2015, Dave Harden, a5_3.cpp
Palindrome checker
gets userinput until quit
*/

#include <iostream>
#include "mystring.h"
#include <cctype>
using namespace std;
using namespace cs2b_mystring;

bool isAPalindrome(myString str1, int lowlim, int uplim);



int main()
{
    myString Bob("abCdeffedcba");
    myString Hey("AC  CA");
    if (Bob[0] == Bob[11])
        cout << "working";
    cout << "cont" << endl;
    isAPalindrome(Bob, 1, 10);
    cout << endl << endl << endl;
    bool temp;
    temp = isAPalindrome(Hey, 0, (Hey.length() - 1));
    //26
    cout << endl;
    cout << temp;
}



bool isAPalindrome(myString str1, int lowlim, int uplim)
{
    cout << "call" << endl;
    if (ispunct(str1[uplim]))
        uplim++;
    else if (ispunct(str1[lowlim]))
        lowlim++;
    if (isspace(str1[uplim]))
        uplim++;
    else if (isspace(str1[lowlim]))
        lowlim++;
    if (lowlim > uplim)
    {
        cout << "testing1" << endl;
        return true;
    }
    if (toupper(str1[lowlim]) != toupper(str1[uplim]))
    {
        cout << "testing2" << endl;
        return false;
    }
    lowlim++;
    uplim--;
    isAPalindrome(str1, lowlim, uplim);
}