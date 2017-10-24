#include <iostream>
#include <string>
#include <sstream>
//I read that just going std:: is better than namespace std
// It seems rather reasonable to use the std::
// rather than having problems with modularity
// Is there any other common library which has
// std::?
using namespace std;

// ALL THE CONFUSION OVER TYPOS
class iTune
{
public:
   static const int MIN_BITRATE = 64;
   static const int MAX_BITRATE = 705;
   static const int MIN_STR_LENGTH = 1;
   static const int MAX_STR_LENGTH = 80;
   static const int MIN_PLAY_TIME = 0;
   static const int MAX_PLAY_TIME = (1000 * 60 * 60);
   static const int DEFAULT_BITRATE = 64;
   static const int DEFAULT_PLAY_TIME = 1;
   static const string DEFAULT_STRING;

private:
   string name;
   string artist;
   int bitrate;
   int total_time;

public:
   iTune();
   iTune(string name, string artist, int bitrate, int total_time);
//Mutators
   bool setName(string name);
   bool setArtist(string name);
   bool setRate(int rate);
   bool setTime(int time);
//Accessors
   string getName();
   string getArtist();
   int getRate();
   int getTime();
//Method
   string toString();
   void display();

};

const string iTune::DEFAULT_STRING = "(undefined)";

//CONSTRUCTS
iTune::iTune()
{
   name = DEFAULT_STRING;
   artist = DEFAULT_STRING;
   bitrate = DEFAULT_BITRATE;
   total_time = DEFAULT_PLAY_TIME;
}

iTune::iTune(string name, string artist, int bitrate, int total_time)
{
   if (setName(name))
      this->name = name;
   if (setArtist(artist))
      this->artist = artist;
   if (setRate(bitrate))
      this->bitrate = bitrate;
   if (setTime(total_time))
      this->total_time = total_time;
}
//ACCESSOR
// And the spec doesn't even really need them o_o
string iTune::getName()
{
   return name;
}

string iTune::getArtist()
{
   return artist;
}

int iTune::getRate()
{
   return bitrate;
}

int iTune::getTime()
{
   return total_time;
}


//MUTATORS
bool iTune::setName(string name)
{
   if ((name.length() > MIN_STR_LENGTH) && (name.length() < MAX_STR_LENGTH))
   {
      this->name = name;
      return true;
   }
   return false;
}

bool iTune::setArtist(string name)
{
   if ((name.length() > MIN_STR_LENGTH) && (name.length() < MAX_STR_LENGTH))
   {
      this->artist = name;
      return true;
   }
   return false;
}

bool iTune::setRate(int rate)
{
   if ((rate > MIN_BITRATE) && (rate < MAX_BITRATE))
   {
      bitrate = rate;
      return true;
   }
   return false;
}

bool iTune::setTime(int time)
{
   if ((time > MIN_PLAY_TIME) && (time < MAX_PLAY_TIME))
   {
      total_time = time;
      return true;
   }
   return false;
}

string iTune::toString()
{
   return (name + " " + artist + " " +
      to_string(bitrate) +" " + to_string(total_time));
}

void iTune::display()
{
   cout << "Music Info" << endl;
   cout << name << endl;
   cout << artist << endl;
   cout << bitrate << endl;
   cout << total_time << endl << endl;
}

int main ()
{
   iTune amazing, whyLife, silly, test1, test2, test3;
//Default
   amazing.display();
//Legal
   whyLife.setName("HEYA");
   whyLife.setArtist("Hi");
   whyLife.setRate(67);
   whyLife.setTime(0);
   whyLife.display();
//QUAD ILLEGAL
   silly.setName("I");
   silly.setArtist("C");
   silly.setRate(705);
   silly.setTime(-1);
   silly.display();
//Greater than 80
   test1.setName("OHMYGODTHISLOOKSSOHORRIBLEIDONTEVENKNOWMAN"
      "PLEASEKILLTHISHORRIBLEMONSTERSTRINGBLAHBLAHBLABHHIASHDOOM");
   test1.setArtist("Never again");
   test1.setRate(63);
   test1.setTime(3600000);
   test1.display();
//Exactly 80
   test2.setName("0123456789012345678901234567890123456789"
      "0123456789012345678901234567890123456789");
   test2.setArtist("Hah I lied");
   test2.setRate(704);
   test2.setTime(3600001);
   test2.display();
//79....
   test3.setName("0123456789012345678901234567890123456789"
      "012345678901234567890123456789012345678");
   test3.setArtist("Artist is a clone of name, not checking both");
   test3.setRate(124);
   test3.setTime(2400);
   test3.display();
//using constructor
   iTune Hai("hi", "hey", 67, 12);
   Hai.display();
   return 0;
}

/* RUN
Music Info
(undefined)
(undefined)
64
1

Music Info
HEYA
Hi
67
1

Music Info
(undefined)
(undefined)
64
1

Music Info
(undefined)
Never again
64
1

Music Info
(undefined)
Hah I lied
704
1

Music Info
0123456789012345678901234567890123456789012345678901234567890123456789012345678
Artist is a clone of name, not checking both
124
2400

Music Info
hi
hey
67
12

Press any key to continue . . .

*/

/*
Patient::Patient( string name, double temperature, int id )
{
   if ( !setName( name ) )
      this->name = DEFAULT_NAME;
   if ( !setTemperature( temperature ) )
      this->temperature = DEFAULT_TEMP;
   if ( !setID( id ) )
      this->id = DEFAULT_ID;
}
*/


/*
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// class prototype
class Patient
{
public:
   static const int MIN_LENGTH = 2;
   static const int MAX_LENGTH = 40;
   static const int MIN_ID = 0;
   static const int MAX_ID = 9999;
   static const double MIN_TEMP;
   static const double MAX_TEMP;
   static const double ALARM_TEMP;
   static const string DEFAULT_NAME;
   static const int DEFAULT_ID = 0;
   static const double DEFAULT_TEMP;

private:
   string name;
   int id;
   double temperature;

public:
   Patient();
   Patient( string name, double temperature, int id );
   void display();

   // Accessors can be done in line:
   double getTemperature() { return temperature; }
   int getID() { return id; }
   string getName() { return name; }
   
   // mutators
   bool setTemperature(double temperature);
   bool setID(int id);
   bool setName(string name);
};

// alternate way to initialize a static (required for not const ints)
const double Patient::ALARM_TEMP = 103.5;
const double Patient::DEFAULT_TEMP = 98.6;
const double Patient::MIN_TEMP = 88.;
const double Patient::MAX_TEMP = 111.;
const string Patient::DEFAULT_NAME = "nobody";

// method prototypes
string getPatientName();
int getPatientID();
double getPatientTemp();

int main()
{
   // instantiate two Patients
   Patient person1, person2;

   // variables to capture input
   string userName;
   double userTemp;
   int userId;

   // get the info for patient #1:
   cout << "Patient #1 ---\n";
   // we built three helper methods for this
   userName = getPatientName();
   userId = getPatientID();
   userTemp = getPatientTemp();

   // set patient #1
   if ( !person1.setName(userName) )
      cout << "Error in patient name: Invalid length.\n";
   if ( !person1.setID(userId) )
      cout << "Error in patient id: out of range.\n";
   if ( !person1.setTemperature(userTemp) )
      cout << "Error in patient temperature:  out of range.\n";


   // get the info for patient #2:
   cout << "Patient #2 ---\n";
   userName = getPatientName();
   userId = getPatientID();
   userTemp = getPatientTemp();

   // set patient #2
   if ( !person2.setName(userName) )
      cout << "Error in patient name: Invalid length.\n";
   if ( !person2.setID(userId) )
      cout << "Error in patient id: out of range.\n";
   if ( !person2.setTemperature(userTemp) )
      cout << "Error in patient temperature:  out of range.\n";

   // display patients
   person1.display();
   person2.display();

   return 0;
}

// main methods (non-Patient methods)
string getPatientName()
{
   string stringIn;
   cout << "What's the patient's name? ";
   getline(cin, stringIn);
   return stringIn;
}

int getPatientID()
{
   int id;
   string stringIn;

   cout << "What's the patient's id #? ";
   getline(cin, stringIn);
   istringstream(stringIn) >> id;
   return id;
}

double getPatientTemp()
{
   double temp;
   string stringIn;

   cout << "What's the patient's temperature? ";
   getline(cin, stringIn);
   istringstream(stringIn) >> temp;
   return temp;
}

// class method definitions
Patient::Patient()
{
   name = DEFAULT_NAME;
   temperature = DEFAULT_TEMP;
   id = DEFAULT_ID;
}
/*
Patient::Patient( string name, double temperature, int id )
{
   if ( !setName( name ) )
      this->name = DEFAULT_NAME;
   if ( !setTemperature( temperature ) )
      this->temperature = DEFAULT_TEMP;
   if ( !setID( id ) )
      this->id = DEFAULT_ID;
}
/
void Patient::display()
{
   cout << "Patient: "
      << "\n  Name: " << name
      << "\n  ID: " << id
      << "\n  Body Temperature: " << temperature << " (F)";
   if (temperature > ALARM_TEMP)
      cout << "\n   *** urgent: attend immediately ***"; 
   cout << endl;
}

// mutators
bool Patient::setTemperature(double temperature)
{
   if (temperature < MIN_TEMP || temperature > MAX_TEMP)
      return false;
   this->temperature = temperature;
   return true;
}

bool Patient::setID(int id)
{
   if (id < MIN_ID || id > MAX_ID)
      return false;
   this->id = id;
   return true;
}

bool Patient::setName( string name)
{
   if (name.length() < MIN_LENGTH || name.length() > MAX_LENGTH)
      return false;
   this->name = name;
   return true;
}

*/