#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int  main()
{
   double DOLLARS_PER_WH = .00005;
   int DAYS_PER_MONTH = 30;
   double mBill;
   int aTime, bTime, cTime;
   int aPower, bPower, cPower;
   string userInput = "";
   
   cout << "ALL RUNTIMES DENOMINATED IN HR/DAY" << endl;
   cout << "ALL CONSUMPTIONS DENOMINATED IN WATTS" << endl << endl;

// Would be 1000x neater if defined a new function

   cout << "APP1 RUNTIME" << endl;
   getline(cin, userInput);
   istringstream(userInput) >> aTime;
   if (aTime < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      cout << "APP1 CONSUMPTION" << endl;
      getline(cin, userInput);
      istringstream(userInput) >> aPower;
   if (aPower < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      mBill = aPower * aTime;
      cout << "APP2 RUNTIME" << endl;
      getline(cin, userInput);
      istringstream(userInput) >> bTime;
   if (bTime < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      cout << "APP2 CONSUMPTION" << endl;
      getline(cin, userInput);
      istringstream(userInput) >> bPower;
   if (bPower < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      mBill += bPower * bTime;
      cout << "APP3 RUNTIME" << endl;
      getline(cin, userInput);
      istringstream(userInput) >> cTime;
   if (cTime < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      cout << "APP3 CONSUMPTION" << endl;
      getline(cin, userInput);
      istringstream(userInput) >> cPower;
   if (cPower < 0)
   {
      cout << "Negative Input" << endl;
      return 0;
   }
   else
      mBill += cPower * cTime;
      mBill *= DAYS_PER_MONTH;
      cout << "Monthy Power Usage:(in WH)" << endl << mBill << endl;
      mBill *= DOLLARS_PER_WH;
      cout << "Monthly Bill:(in USD)" << endl << mBill << endl;
   return 0;
}