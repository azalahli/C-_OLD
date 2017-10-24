#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{ 
   string command;

   int balance = 5000;
   string nInput;
   int mAmount;

   cout << "This is your starting balance: " << balance << endl;
   while (true)
   {
// clears mAmount so that if u w and no input it works
// double command in row would repeat prev if no input
      mAmount = 0;
      cout <<  endl << "Select:" << endl;
      cout << "Withdrawal?: w" << endl;
      cout << "Deposit?: d" << endl;
      cout << "Balance?: b" << endl;
      cout << "Quit?: q" << endl;

      getline(cin, command);
      
      if (command[0] == 'q' || command[0] == 'Q')
      {
         break;
      }
      if (command[0] == 'w' || command[0] == 'W')
      {
         cout << "How much?\n";
         getline(cin, nInput);
         istringstream(nInput) >> mAmount;
         if (mAmount < 0)
         {
            cout << endl << "Neg Input" << endl;
            continue;
         }
         if (mAmount > balance)
         {
            cout << endl << "Not enough cash :(" << endl;
            continue;
         }
         balance -= mAmount;
         cout << "Balance is:" << balance << endl;
         continue;
      }

      if (command[0] == 'd' || command[0] == 'D')
      {
         cout << "How much? \n";
         getline(cin, nInput);
         istringstream(nInput) >> mAmount;
         if (mAmount < 0)
         {
            cout << endl << "Neg Input" << endl;
            continue;
         }
         balance += mAmount;
         cout << "Balance is:" << balance << endl;
         continue;
      }

      if (command[0] == 'b' || command[0] == 'B')
      {
         cout << "Balance is:" << balance << endl;
         continue;
      }
   cout << endl << "VALID INPUT PLS" << endl;
   }
   
   cout << "\nGood bye.\n\n";
   return 0;
}
/* RUN
This is your starting balance: 5000

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
5000
Balance is:0

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
b
Balance is:0

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
d
How much?
5000
Balance is:5000

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
b
Balance is:5000

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
d
How much?
5000
Balance is:10000

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
10000
Balance is:0

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?

Balance is:0

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
40

Not enough cash :(

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
-10

Neg Input

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
d
How much?
-20

Neg Input

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
dEPOSIT
How much?
40
Balance is:40

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
wIDdawwdslk
How much?
25
Balance is:15

// Most proud about \n not returning a r6010 error xD
// got like 50 of them with using string.at(0)
Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q


VALID INPUT PLS

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
e

VALID INPUT PLS

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
d
How much?
-6000

Neg Input

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
b
Balance is:15

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
30

Not enough cash :(

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
w
How much?
15
Balance is:0

Select:
Withdrawal?: w
Deposit?: d
Balance?: b
Quit?: q
QUIT

Good bye.

Press any key to continue . . .
*/
