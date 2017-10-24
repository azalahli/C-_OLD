// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int doubleNumber(int x)
{
	return x * 2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std; 
	cout << "Number" << endl;
	int x;
	cin >> x;
	x = doubleNumber(x);
	cout << x << endl;
	return 0;
}

