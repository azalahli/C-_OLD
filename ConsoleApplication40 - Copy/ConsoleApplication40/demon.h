/*Myron Pow, CS2B, 7/21/15, Dave Harden, demon.h
header file for demon
*/
#include "creature.h"
#include "string"
#ifndef Demon
#define Demon
class demon : public creature
{

public:
    demon();
    demon(int str, int hp);
    int getDamage();
    std::string getSpecies();
    
};


#endif