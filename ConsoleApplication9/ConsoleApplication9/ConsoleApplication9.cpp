// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main (int x, int y, char z)
{
	using namespace std;
	cin >> x;
	cin >> y;
	cin >> z;
switch (z)
{

case '+':
cout << x + y << endl;
break;
case '-':
cout << x - y << endl;
break;
case '*':
cout << x * y << endl;
break;
case '/':
cout << x / y << endl;
break;
default:
	cout << "Error" << endl;
	exit(1);


}
	return 0;
}
/*

int main(int nX, int nY, char chOperator)
{ using namespace std;
cin >> nX;
cin >> nY;
cin >> chOperator;
    switch (chOperator)
    {
        case '+':
            cout << nX + nY;
			break;
        case '-':
            cout << nX - nY;
			break;
        case '*':
            cout << nX * nY;
			break;
        case '/':
            cout << nX / nY;
			break;
        default:
            cout << "Error" << endl;
            exit(1);
    }
}
*/