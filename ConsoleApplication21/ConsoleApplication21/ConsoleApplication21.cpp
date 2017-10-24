#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// FUNCTION PROTOTYPES
//seems like they could all be void and cout in function
string getString();
string convertToUpper(string x);
string convertToLower(string x);
//should be possible to combine vowels and cons w/
//.isalpha() b4 switch
int countVowels(string x);
int countConsonants(string x);
string reverseString(string x);

// SYMBOLIC CONSTANTS
const int minlength = 4;

int main()
{
   string original;
   string modstring;
   int counter;

   original = getString();
   modstring = convertToUpper(original);
   cout << "Uppercase: ";
   cout << modstring << endl;
   modstring = convertToLower(original);
   cout << "Lowercase: ";
   cout << modstring << endl;
   counter = countVowels(original);
   cout << "# of Vowels: ";
   cout << counter << endl;
   counter = countConsonants(original);
   cout << "# of Consonants: ";
   cout << counter << endl;
   modstring = reverseString(original);
   cout << "Reverse: ";
   cout << modstring << endl;
   cout << "Proof that string is unmodded" << endl;
   cout << original << endl;
   return 0;
}

string getString()
{
   bool valid = true;
   while (valid)
   {
      string input;
      // how do I replace that 4 with minlength?
      // so that it uses the constant
      cout << ("Please input a string longer than 4 chars") << endl;
      getline(cin, input);
      if (input.length() >= minlength)
      {
         valid = !valid;
         return input;
      }
      else
         cout << "Invalid input received" << endl;
   }
   //DEATH TO ERROR MESSAGES
   return "How on Earth did you get this?";
}

string convertToUpper(string x)
{
   string returnstr = "";
   for (int n = 0; n < x.length(); n++)
      returnstr += toupper(x[n]);
   return returnstr;
}

string convertToLower(string x)
{
   string returnstr = "";
   for (int n = 0; n < x.length(); n++)
      returnstr += tolower(x[n]);
   return returnstr;
}

int countVowels(string x)
{
   int counter = 0;
   char temp;
   for (int n = 0; n < x.length(); n++)
   {
      temp = tolower(x[n]);
// Style Guidelines don't have stuff for switch,
// so i indented switch body
      switch (temp)
      {
         case 'a':
         case 'e':
         case 'i':
         case 'o':
         case 'u':
            counter++;
            break;
      }
   }
   return counter;
}

int countConsonants(string x)
{
   int counter = 0;
   char temp;
   for (int n = 0; n < x.length(); n++)
   {
      temp = tolower(x[n]);
// Style Guidelines don't have stuff for switch,
// so i indented switch body
      switch (temp)
      {
             //a
         case 'b':
         case 'c':
         case 'd':
             //e
         case 'f':
         case 'g':
         case 'h':
             //i
         case 'j':
         case 'k':
         case 'l':
         case 'm':
         case 'n':
             //o
         case 'p':
         case 'q':
         case 'r':
         case 's':
         case 't':
             //u
         case 'v':
         case 'w':
         case 'x':
         case 'y':
         case 'z':
            counter++;
            break;
      }
   }
   return counter;
}

string reverseString(string x)
{
   string reverse = "";
   for (int n = (x.length() - 1); n >= 0; n--)
      reverse += x[n];
   return reverse;
}

/* RUNS
Please input a string longer than 4 chars
AbCdEfGhI!@#!@$!@$!@#!~!@~!#~ ~! ~#~ $#$%
Uppercase: ABCDEFGHI!@#!@$!@$!@#!~!@~!#~ ~! ~#~ $#$%
Lowercase: abcdefghi!@#!@$!@$!@#!~!@~!#~ ~! ~#~ $#$%
# of Vowels: 3
# of Consonants: 6
Reverse: %$#$ ~#~ !~ ~#!~@!~!#@!$@!$@!#@!IhGfEdCbA
Proof that string is unmodded
AbCdEfGhI!@#!@$!@$!@#!~!@~!#~ ~! ~#~ $#$%
Press any key to continue . . .

//RUN 2

Please input a string longer than 4 chars

Invalid input received
Please input a string longer than 4 chars

Invalid input received
Please input a string longer than 4 chars

Invalid input received
Please input a string longer than 4 chars

Invalid input received
Please input a string longer than 4 chars

Invalid input received
Please input a string longer than 4 chars
asd
Invalid input received
Please input a string longer than 4 chars
asdf
Uppercase: ASDF
Lowercase: asdf
# of Vowels: 1
# of Consonants: 3
Reverse: fdsa
Proof that string is unmodded
asdf
Press any key to continue . . .

*/



/*
int main ()
{
  char c;
  for (c = 'A' ; c <= 'Z' ; c++) putchar (c);

  return 0;
}

int main ()
{
    string cstr = "Hello";
    //for(int n = 0; char c = cstr[n]; ++n)
      //  std::cout << c;
    //std::cout << '\n';
    cout << cstr[0];
   }
*/
//Switch statement with isalpha applied to inputs
