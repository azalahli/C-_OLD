/*Myron Pow, CS2B, 7/21/15, Dave Harden, creatures.cpp
source file for creatures
*/
#include "creature.h"
#include "string"
#include <iostream>
using namespace std;


creature::creature()
{
    hitpoints = 10;
    strength = 10;
}



creature::creature(int newStrength, int newHit)
{
    strength = newStrength;
    hitpoints = newHit;
}



int creature::getDamage()
{
    int damage;
    damage = (rand() % strength) + 1;
    cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}


string creature::getSpecies()
{
    return "creature";
}






//Accessors


int creature::getStrength()
{
    return strength;
}



int creature::getHitpoints()
{
    return hitpoints;
}







//Mutators

void creature::setStrength(int str)
{
    strength = str;
}



void creature::setHitpoints(int hp)
{
    hitpoints = hp;
}