/*Myron Pow, CS2B, 7/21/15, Dave Harden, balrog.h
header file for balrog
*/

#include "demon.h"
#include "string"
#ifndef Balrog
#define Balrog
class balrog : public demon
{

public:
    balrog();
    balrog(int str, int hp);
    int getDamage();
    std::string getSpecies();
};


#endif