/* Myron Pow, CS2B, 7/18/2015, Dave Harden, a5_1.cpp
Program reverses things via recursion
Client is prepreped
*/


#include <iostream>
#include <cstring>;

using namespace std;

void reverseWithinBounds(char *str, int lowlim, int uplim);
void reverseCstring (char *str);


int main()
{
    cout << "Pre defined strings, reverseWithinBounds" << endl;
    char* test1 = {"hello"};
    char* test2 = "abcdefghijklmnopqrstuvwxyz";
    char test3[] = "Hello World!";
    cout << "test1 = hello" << endl;
    cout << "test2 = abcdefghijklmnopqrstuvwxyz" << endl;
    cout << "test3 = Hello World!" << endl << endl;
    cout << "reverseWithinBounds(test1 ,0, 3)" << endl;
    reverseWithinBounds(test1 ,0, 3); 
    cout << "reverseWithinBounds(test2 ,2, 5);" <<endl;
    reverseWithinBounds(test2 ,2, 5);
    cout << "reverseWithinBounds(test3 ,2, 7);" <<endl;
    reverseWithinBounds(test3 ,2, 7);
    cout << "REVERSE CSTRING" << endl;
    cout << "reverseCstring(test1);" << endl;
    reverseCstring(test1);
    cout << "reverseCstring(test2);" << endl;
    reverseCstring(test2);
    cout << "reverseCstring(test3);" << endl;
    reverseCstring(test3);
}






void reverseWithinBounds(char *str, int lowlim, int uplim)
{
    if (lowlim > uplim)
    {
        cout <<  '\n' << '\n';
        return;
    }
    cout << str[uplim--];
    reverseWithinBounds(str, lowlim , uplim);
}







void reverseCstring (char *str)
{
    reverseWithinBounds(str, 0, (strlen(str) - 1));
}


/*run
Pre defined strings, reverseWithinBounds
test1 = hello
test2 = abcdefghijklmnopqrstuvwxyz
test3 = Hello World!

reverseWithinBounds(test1 ,0, 3)
lleh

reverseWithinBounds(test2 ,2, 5);
fedc

reverseWithinBounds(test3 ,2, 7);
oW oll

REVERSE CSTRING
reverseCstring(test1);
olleh

reverseCstring(test2);
zyxwvutsrqponmlkjihgfedcba

reverseCstring(test3);
!dlroW olleH

Press any key to continue . . .
*/