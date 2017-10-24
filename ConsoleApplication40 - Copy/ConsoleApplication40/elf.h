/*Myron Pow, CS2B, 7/21/15, Dave Harden, elf.h
header file for elf
*/
#include "creature.h"
#include "string"
#ifndef Elf
#define Elf

class elf : public creature
{
public:
    elf();
    elf(int str, int hp);
    int getDamage();
    std::string getSpecies();
};


#endif