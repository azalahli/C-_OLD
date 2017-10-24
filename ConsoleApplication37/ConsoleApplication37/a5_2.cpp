/* Myron Pow, CS2B, 7/18/2015, Dave Harden, a5_2.cpp
Palindrome checker
gets userinput until quit
*/
#include <iostream>
#include "mystring.h"
#include <cctype>
using namespace std;
using namespace cs2b_mystring;

bool isAPalindrome(myString &str1, signed int lowlim, signed int uplim);




int main()
{
    bool quit = false;
    while (!quit)
    {
        char  input[127];
        cin.getline(input, 127, '\n');
        myString temp(input);
        if (temp == "quit")
        {
            exit(0);
        }
        if (isAPalindrome(temp, 0, (temp.length() - 1)))
        {
            cout << temp << " is a palindrome" << endl;
        }
        else cout << temp << " is not a palindrome" << endl;
    }
}




//pre mystring object, lower and upper bounds of the string
//post bool value true if palindrome
bool isAPalindrome(myString &str1, signed int lowlim, signed int uplim)
{
    if (ispunct(str1[uplim]))
        uplim--;
    if (ispunct(str1[lowlim]))
        lowlim++;
    if (isspace(str1[uplim]))
        uplim--;
    if (isspace(str1[lowlim]))
        lowlim++;
    if (lowlim >= uplim)
    {
        return true;
    }
    if (toupper(str1[lowlim]) != toupper(str1[uplim]))
    {
        return false;
    }
    isAPalindrome(str1, ++lowlim, --uplim);
}

/*run
peanuts
peanuts is not a palindrome
Able was I, ere I saw elba
Able was I, ere I saw elba is a palindrome
quit
Press any key to continue . . .
*/
