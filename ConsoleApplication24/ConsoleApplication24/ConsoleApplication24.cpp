#include <iostream>
#include <string>
using namespace std;

const int DYING = -10;

class chr
{
   std::string name;
   int hp;
   int dr;
   int ac;
   int hit;
   int dmg;
   bool mag;
   bool div;

   public:
      chr();
      friend void Attack (chr atk, chr &def);
      bool sethp(int hp);
      bool setac(int ac);
      bool sethit(int hit);
      bool setdr(int dr);
      bool setdmg(int dmg);
      void chrgen ();
      int gethp();
      void printout();



};

void chr::printout()
{
   cout << "STATS OF CHAR" << endl;
   cout << hp << endl;
   cout << dr << endl;
   cout << ac << endl;
   cout << hit << endl;
   cout << dmg << endl;
   cout << mag << endl;
   cout << div << endl;
}

void chr::chrgen()
{
   hp = 10;
   dr = 10;
   ac = 10;
   hit = 12;
   dmg = 20;
   mag = rand() % 2;
   div = rand() % 2;
}

/*
void chr::chrgen(chr chname)
{
   hp = rand() % 100 + 1;
   dr = rand() % 5 + 10;
   ac = rand() % 5 + 1;
   hit = rand() % 8 + 13;
   mag = rand() % 2;
   dmg = rand() % 12 + 1;
}
*/
chr::chr()
{
   hp = 0;
   dr = 0;
   ac = 0;
   hit = 0;
   mag = false;
   dmg = 0;
}

int chr::gethp()
{
   return hp;
}

bool chr::sethp(int temp)
{
   if (temp > 0)
   {
      hp = temp;
      return true;
   }
   else
      return false;
}

bool chr::setac(int temp)
{
   if (temp > 0)
   {
      ac = temp;
      return true;
   }
   else
      return false;
}

bool chr::sethit(int temp)
{
   if (temp > 0)
   {
      hit = temp;
      return true;
   }
   else
      return false;
}

bool chr::setdr(int temp)
{
   if (temp > 0)
   {
      dr = temp;
      return true;
   }
   else
      return false;
}

bool chr::setdmg(int temp)
{
   if (temp > 0)
   {
      dmg = temp;
      return true;
   }
   else
      return false;
}

/*
int Attack (chr atk, chr def)
{
   if (atk.hit > def.ac)
   {
      def.hp = (def.hp - ((atk.dmg - def.dr) > 0) ? (atk.dmg - def.dr):0);
      return def.hp;
   }
   return def.hp;
}
*/

void Attack (chr atk, chr &def)
{
   if ((atk.hit > def.ac) && ((atk.dmg - def.dr) > 0))
   {
      def.hp -= (atk.dmg - def.dr);
   }
}

//int main ()
//{
//   chr 
//}


int main ()
{
   chr Bob, Joe, Bomb, dude, hi, bye;
   Bob.sethp(10), Bob.setac(5), Bob.sethit(10), Bob.setdmg(10), Bob.setdr(10);
   Joe.sethp(10), Joe.setdr(4), Joe.setac(7);
   cout << Bob.gethp() << endl;
   Attack(Bob, Joe);
   cout << Joe.gethp() << endl;
   Attack(Bob, Joe);
   cout << Joe.gethp();
   Bomb.chrgen();
   dude.chrgen();
   hi.chrgen();
   bye.chrgen();
   Attack(Bomb, dude);
   Bomb.printout();
   dude.printout();
   hi.printout();
   bye.printout();



}




























/*

class Galaxy
{
private:
   string name;
   double magnitude;
public:
   // default constructor
   Galaxy();

   // mutators and accessors
   bool setMagnitude(double mag);
   bool setName(string theName);
   string getName();
   double getMagnitude();
};


// -------- Galaxy Member Functions ------------
// default constructor
Galaxy::Galaxy()
{
   name = "undefined";
   magnitude = 0.0;   
}

// mutators "set" methods
bool Galaxy::setMagnitude(double mag)
{
   if (mag < -3 || mag > 30)
     return false;
   // else
   magnitude = mag;
   return true; 
}
bool Galaxy::setName(string theName)
{
   if (theName.length() < 2)
      return false;
   // else we fall through
   name = theName;
   return true;
}
// accessor "get" methods 
string Galaxy::getName()
{
   return name;
}
double Galaxy::getMagnitude()
{
   return magnitude;
}

// main method ---------------------------------
int  main()
{
   // declare the objects
   Galaxy gal1, gal2;
      
   // try to set the data
   gal1.setName("X");
   gal1.setMagnitude(100);
   gal2.setName("Stephan's Third");
   gal2.setMagnitude(13.2);
   
   // let's see what happened
   cout << "Gal #1 name: " << gal1.getName() << endl;
   cout << "Gal #1 mag: " << gal1.getMagnitude() << endl;
   cout << "Gal #2 name: " << gal2.getName()<< endl;
   cout << "Gal #2 mag: " << gal2.getMagnitude()<< endl;

   return 0;
}
*/