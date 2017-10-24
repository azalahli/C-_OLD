/*Myron Pow, CS2B, 7/21/15, Dave Harden, elf.cpp
source file for elf
*/
#include "creature.h"
#include "elf.h"
#include "string"
#include <iostream>
using namespace std;

const int magicChance = 50; //percent chance to deal double damage



elf::elf()
{
    setHitpoints(10);
    setStrength(10);
}



elf::elf(int str, int hp)
    :creature (str, hp)
{
}

int elf::getDamage()
{
    int damage = creature::getDamage();
    int crit = (rand() % 100) + 1;
    cout << "The " << getSpecies() << " attacks for " << damage << " points!"
        << endl;
    if (crit <= magicChance)
    {
        cout << "Magical attack inflicts " << damage << " additional damage points!"
            << endl;
        damage *= 2;
    }
    return damage;
}

//I seriously hope that just writing the string literal here
//is ok, as it takes more code to declare it a const
string elf::getSpecies()
{
    return "elf";
}