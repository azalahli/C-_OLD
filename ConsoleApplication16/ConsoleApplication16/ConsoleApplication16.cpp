#include <iostream>
using namespace std;
int  main()
{
   cout << "lName = Pow" << endl;
   cout << "ID = REDACTED" << endl;
   int myId = 21;
   int nLet = 3;
   int iResult;
   double dResult;
   bool bResult;
   cout << "sum of ID numbers: " << myId << endl;
   cout << "# of char in lName: " << nLet << endl;
   iResult = myId / 2;
   cout << "E1: " << iResult << endl;
   iResult = myId % 2;
   cout << "E2: " << iResult << endl;
   iResult = 2 + nLet;
   cout << "E3: " << iResult << endl;
   iResult = myId + nLet;
   cout << "E4: " << iResult << endl;
   iResult = myId * nLet;
   cout << "E5: " << iResult << endl;
   iResult = myId += nLet;
   cout << "E6: " << iResult << endl;
   iResult = myId *= nLet;
   cout << "E7: " << iResult << endl;
   iResult = nLet++;
   cout << "E8: " << iResult << endl;
   iResult = ++nLet;
   cout << "E9: " << iResult << endl;
   dResult = (static_cast<double>(myId))/(nLet + 1100);
//Should you cast both vars?
   cout << "E10: " << dResult << endl;
   bResult = (nLet % nLet) && (myId * myId);
   cout << "E11: " << bResult << endl;
   bResult = (nLet -= nLet) || (myId);
   cout << "E12: " << bResult << endl;
}
