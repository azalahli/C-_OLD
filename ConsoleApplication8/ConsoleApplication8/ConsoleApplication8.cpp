// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Adv 
{
	int shown;
	float clicks;
	float avgrev;

};
float TR(Adv User)
{
	float TotalRev;
	TotalRev = User.shown * User.clicks * User.avgrev;
	return TotalRev;
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	Adv Bucket;
	cout << "Ads seen?" << endl;
	cin >> Bucket.shown;
	cout << "%Clicked" << endl;
	cin >> Bucket.clicks;
	cout << "Average Revenue?" << endl;
	cin >> Bucket.avgrev;
	cout << TR(Bucket);


	return 0;
}

