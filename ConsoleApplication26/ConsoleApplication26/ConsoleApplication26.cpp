#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class DateProf
{
   static const char DEFAULT_CHAR;
   static const int DEFAULT_INT;
   static const string DEFAULT_NAME;
//Just in case you ever want to modify the multipliers
   static const double PERFECT;
   static const double AMAZING;
   static const double GREAT;
   static const double GOOD;
   static const double AVERAGE;
   static const double BLWAVG;
   static const double BAD;
   static const double HORRIBLE;
   static const double WHY;
   static const double NOPE;
   static const double NEVER;

//LIMITS ARE INCLUSIVE
   static const int IMAX = 10;
   static const int IMIN = 1;
   static const int STRMAX = 80;
   static const int STRMIN = 1;
//IMPORTANT STUFF
   char gender;
   char genderPref;
   int romance;
   int finance;
   string name;

public:
   DateProf();
   DateProf(char gen, char genPref, int rom, int fin, string nam);

   char getGender();
   char getGenderPref();
   int getRomance();
   int getFinance();
   string getName();

   bool setGender(char gen);
   bool setGenderPref(char genPref);
   bool setRomance(int rom);
   bool setFinance(int fin);
   bool setName(string nam);

   double determineGenFit(DateProf other);
   double determineRomFit(DateProf other);
   double determineFinFit(DateProf other);
   double fitVal(DateProf other);


};

const char DateProf::DEFAULT_CHAR = 'N';
const int DateProf::DEFAULT_INT = 0;
const string DateProf::DEFAULT_NAME = "N/A";
const double DateProf::PERFECT = 1.0;
const double DateProf::AMAZING = .9;
const double DateProf::GREAT = .8;
const double DateProf::GOOD = .7;
const double DateProf::AVERAGE = .6;
const double DateProf::BLWAVG = .5;
const double DateProf::BAD = .4;
const double DateProf::HORRIBLE = .3;
const double DateProf::WHY = .2;
const double DateProf::NOPE = .1;
const double DateProf::NEVER = 0.0;



DateProf::DateProf()
{
   gender = DEFAULT_CHAR;
   genderPref = DEFAULT_CHAR;
   romance = DEFAULT_INT;
   finance = DEFAULT_INT;
   name = DEFAULT_NAME;
}

DateProf::DateProf(char gen, char genPref, int rom, int fin, string nam)
{
   setGender(gen);
   setGenderPref(genPref);
   setRomance(rom);
   setFinance(fin);
   setName(nam);
}

char DateProf::getGender()
{
   return gender;
}

char DateProf::getGenderPref()
{
   return genderPref;
}

int DateProf::getRomance()
{
   return romance;
}

int DateProf::getFinance()
{
   return finance;
}

string DateProf::getName()
{
   return name;
}

bool DateProf::setGender(char gen)
{
   char temp;
   temp = toupper(gen);
   switch(temp)
   {
      case 'M':
         gender = temp;
         break;
      case 'F':
         gender = temp;
         break;
      default:
         gender = DEFAULT_CHAR;
         return false;
         break;
   }
   return true;
}

bool DateProf::setGenderPref(char genPref)
{
   char temp;
   temp = toupper(genPref);
   switch(temp)
   {
      case 'M':
         genderPref = temp;
         break;
      case 'F':
         genderPref = temp;
         break;
      default:
         genderPref = DEFAULT_CHAR;
         return false;
         break;
   }
   return true;
}

bool DateProf::setRomance(int rom)
{
   if ((rom <= IMAX) && (rom >= IMIN))
   {
      romance = rom;
      return true;
   }
   romance = NEVER;
   return false;
}

bool DateProf::setFinance(int fin)
{
   if ((fin <= IMAX) && (fin >= IMIN))
   {
      finance = fin;
      return true;
   }
   finance = NEVER;
   return false;
}

//No explicit qualifiers in spec
//Here to prevent overflow
bool DateProf::setName(string nam)
{
   if ((nam.length() <= STRMAX) && (nam.length() >= STRMIN))
   {
      name = nam;
      return true;
   }
   return false;
}

double DateProf::determineGenFit(DateProf other)
{
   if ((gender == other.genderPref) && (genderPref == other.gender))
   {
      return PERFECT;
   }
   return NEVER;
}

double DateProf::determineRomFit(DateProf other)
{
// Test needed to ensure that illegal comparisons to self return 0
   int temp = 10;
   if ((romance != 0) && (other.romance != 0))
      temp = abs(romance - other.romance);
   switch(temp)
   {
      case 0:
         return PERFECT;
         break;
      case 1:
         return AMAZING;
         break;
      case 2:
         return GREAT;
         break;
      case 3:
         return GOOD;
         break;
      case 4:
         return AVERAGE;
         break;
      case 5:
         return BLWAVG;
         break;
      case 6:
         return BAD;
         break;
      case 7:
         return HORRIBLE;
         break;
      case 8:
         return WHY;
         break;
      case 9:
         return NOPE;
         break;
   }
   return NEVER;
}

double DateProf::determineFinFit(DateProf other)
{
   // Test needed to ensure that illegal comparisons to self return 0
   int temp = 10;
   if ((finance != 0) && (other.finance != 0))
      temp = abs(finance - other.finance);
   switch(temp)
   {
      case 0:
         return PERFECT;
         break;
      case 1:
         return AMAZING;
         break;
      case 2:
         return GREAT;
         break;
      case 3:
         return GOOD;
         break;
      case 4:
         return AVERAGE;
         break;
      case 5:
         return BLWAVG;
         break;
      case 6:
         return BAD;
         break;
      case 7:
         return HORRIBLE;
         break;
      case 8:
         return WHY;
         break;
      case 9:
         return NOPE;
         break;
   }
   return NEVER;
}

double DateProf::fitVal(DateProf other)
{
   return (determineGenFit(other) * determineRomFit(other) *
          (determineFinFit(other)));
}



int main()
{
   //Test cases cannot be exaustively tested with 4 instances
   //all names 3 char long for ease of reading
   DateProf Bob('M', 'm', 10, 3, "Bob");
   DateProf Joe('M', 'm', 2, 4, "Joe");
   DateProf Mia('f', 'm', 0, 9, "Mia");
   DateProf Gal('F', 'f', 10, 12, "Gal");
//Class has no output function
   cout << Bob.getName() << endl;
   cout << Bob.getName() << " " << Bob.fitVal(Bob) << endl;
   cout << Joe.getName() << " " << Bob.fitVal(Joe) << endl;
   cout << Mia.getName() << " " << Bob.fitVal(Mia) << endl;
   cout << Gal.getName() << " " << Bob.fitVal(Gal) << endl;

   cout << Joe.getName() << endl;
   cout << Bob.getName() << " " << Joe.fitVal(Bob) << endl;
   cout << Joe.getName() << " " << Joe.fitVal(Joe) << endl;
   cout << Mia.getName() << " " << Joe.fitVal(Mia) << endl;
   cout << Gal.getName() << " " << Joe.fitVal(Gal) << endl;

      cout << Mia.getName() << endl;
   cout << Bob.getName() << " " << Mia.fitVal(Bob) << endl;
   cout << Joe.getName() << " " << Mia.fitVal(Joe) << endl;
   cout << Mia.getName() << " " << Mia.fitVal(Mia) << endl;
   cout << Gal.getName() << " " << Mia.fitVal(Gal) << endl;

      cout << Gal.getName() << endl;
   cout << Bob.getName() << " " << Gal.fitVal(Bob) << endl;
   cout << Joe.getName() << " " << Gal.fitVal(Joe) << endl;
   cout << Mia.getName() << " " << Gal.fitVal(Mia) << endl;
   cout << Gal.getName() << " " << Gal.fitVal(Gal) << endl;
}

/* Run
Bob
Bob 1
Joe 0.18
Mia 0
Gal 0
Joe
Bob 0.18
Joe 1
Mia 0
Gal 0
Mia
Bob 0
Joe 0
Mia 0
Gal 0
Gal
Bob 0
Joe 0
Mia 0
Gal 0
Press any key to continue . . .
*/
