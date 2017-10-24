//Program to demonstrate use of the Stack template class.
#include <iostream>
#include "stack.h"
#include "stack.cpp"
using std::cin;
using std::cout;
using std::endl;
using StackSavitch::Stack;
using StackSavitch::pop_empty_stack_exception;

int main( )
{
    try
    {
        Stack<char> noError;
        noError.push('n');
        cout << noError.pop() << endl;
        Stack<char> aStack; 
        aStack.pop();
    }
    catch (pop_empty_stack_exception)
    {
        cout << "Is it really this simple?" << endl;
    }
    return 0;

}

/*run
n
Is it really this simple?
Press any key to continue . . .
*/