#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class OldCellPhone
{
public:
   static const int MIN_CAP = 10;
   static const int MAX_CAP = 1000;
   static const string DEFAULT_DSCR;
   static int HI;

private:
   string description;
   int    memCapacity;
   bool   camera;
   bool   gps;  
public:
   OldCellPhone(string dscr = DEFAULT_DSCR, int mem = MIN_CAP,
         bool cam = false, bool gp = false);
   string toString();
   bool setMemCapacity(int mem);
   void setCamera( bool hasCam ) { camera = hasCam; }
   void setGps( bool hasGps ) { gps = hasGps; }
   static void hello ();
   static int hr ();
 };

int OldCellPhone::HI = 1;
void OldCellPhone::hello()
{
   HI = 12;
}
int OldCellPhone::hr()
{
   return HI;
}
int update( int userIn )
{
   userIn++;
   return userIn;
}

int main()
{
//OldCellPhone::hello();
//cout << OldCellPhone::hr();
//int clientVal = 1;
//update( clientVal  );
//cout << clientVal;
double answer;
int num1 = 11;
answer =  (num1 + 1) / 100. ;
cout << answer;
}