/*Myron Pow, CS2B, 7/21/15, Dave Harden, cyberdemon.h
header file for cyberdemon
*/
#include "demon.h"
#include "string"
#ifndef Cyberdemon
#define Cyberdemon
class cyberdemon : public demon
{

public:
    cyberdemon();
    cyberdemon(int str, int hp);
    int getDamage();
    std::string getSpecies();
    
};


#endif