#include <iostream>
#include <string>
#include <sstream>
//#include <time.h>
#include <cstdlib>
using namespace std;

int getBet ();
string pullOne();
int getPayMultiplier(string s1, string s2, string s3);
void diplayWin(string s1, string s2, string s3, int prize);

string const CARD1 = "Bar";
string const CARD2 = "Seven";
string const CARD3 = "Cherries";
string const CARD4 = "Space";

int main()
{
   while("FOREVER AND EVER")
   {
      int winnings;
      string pull;
      string pull2;
      string pull3;
      pull = pullOne();
      pull2 = pullOne();
      pull3 = pullOne();
      winnings = getBet();
      winnings *= getPayMultiplier(pull, pull2, pull3);
      diplayWin (pull, pull2, pull3, winnings);
   }
   return 0;
}

int getBet()
{
   bool valid = true;
   while(valid)
   {
      string input;
      int bet;
      cout << "Make a Bet; 1-100, 0 for quit" << endl;
      getline(cin, input);
      istringstream(input) >> bet;
      if (bet == 0)
      {
         cout << "Bye" << endl;
         exit(0);
      }
      if ((100 >= bet) && (bet >= 1))
      {
         return bet;
      } 
      else
         cout << "1-100 please" << endl << endl;
   }
//ERRORS AHOY
   return 1;
}

string pullOne()
{
   //srand (time(NULL));
   string pull = "Error";
   int tmp = rand() % 4;
   switch(tmp)
   {
      case 0:
         pull = CARD1;
         break;
      case 1:
         pull = CARD2;
         break;
      case 2:
         pull = CARD3;
         break;
      case 3:
         pull = CARD4;
         break;
   }
   return pull;
}

// this is so much nicer to read ;-;

int getPayMultiplier (string s1, string s2, string s3)
{
   if ((s1 == CARD3) && (s2 != CARD3))
      return 3;
   if ((s1 == CARD3) && (s2 == CARD3) && (s3 != CARD3))
      return 10;
   if ((s1 == CARD3) && (s2 == CARD3) && (s3 == CARD3))
      return 20;
   if ((s1 == CARD1) && (s2 == CARD1) && (s3 == CARD1))
      return 35;
   if ((s1 == CARD2) && (s2 == CARD2) && (s3 == CARD2))
      return 50;
   else
      return 0;
}

void diplayWin(string s1, string s2, string s3, int prize)
{
   cout << s1 << " " << s2 << " " << s3 << " " << endl;
   if (prize == 0)
   {
      cout << "Sucker :P" << endl << endl;
   }
   else
      cout << prize << endl << endl;
}

// Switch statements for strings?
// Why do we even bother making the pull function 
// return strings?
// Nested if's are ugly as hell
/*
int getPayMultiplier(string s1, string s2, string s3)
{
   if (s1 == CARD3)
   {
      if (s2 != CARD3)
      {
         return 3;
      }
      else
      {
         if (s3 != CARD3)
         {
            return 10;
         }
         else
         {
            return 20;
         }
      }
   }
   else
   {
      if (s1 == CARD1)
      {
         if (s2 == CARD1)
            if (s3 == CARD1)
               return 35;
      }
      else
      {
         if (s1 == CARD2)
         {
            if (s2 == CARD2)
               if (s3 == CARD2)
                  return 50;
         }
         else
            return 0;
      }
   }
   return 0;
}
*/

/*
*/