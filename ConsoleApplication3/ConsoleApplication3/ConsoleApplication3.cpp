// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	cout << "Get numbers" << endl;
	int x = Readnumber();
	int y = Readnumber();
	WriteAnswer(x + y);
	return 0;
}
