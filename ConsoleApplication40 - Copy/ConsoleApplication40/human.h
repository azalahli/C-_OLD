/*Myron Pow, CS2B, 7/21/15, Dave Harden, human.h
header file for human
*/
#include "creature.h"
#include "string"
#ifndef Human
#define Human

class human : public creature
{
public:
    human();
    human(int str, int hp);
    //int getDamage();
    std::string getSpecies();
};


#endif