// ConsoleApplication1.cpp : Defines the entry point for the console application.

//

#include "stdafx.h"
#include <iostream>

int	sub(int i, int j) {
	 int result = i - j;
	 return result;
}
int main(int argc, _TCHAR* argv[])
{
	using namespace std;
	int i = 0;
	int j = 2;
	int k = sub(i, j);
	cout << k << endl << i << endl;
	return 0;
}

