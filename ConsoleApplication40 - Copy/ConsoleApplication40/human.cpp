/*Myron Pow, CS2B, 7/21/15, Dave Harden, human.cpp
source file for human
*/
#include "creature.h"
#include "human.h"
#include "string"
#include <iostream>
using namespace std;



human::human()
{
    setHitpoints(10);
    setStrength(10);
}



human::human(int str, int hp)
    :creature (str, hp)
{
}
/*
int human::getDamage()
{
    int damage = creature::getDamage();
    //cout << "The " << getSpecies() << " attacks for " << damage << " points!"
    //    << endl;
    return damage;
}
*/

string human::getSpecies()
{
    return "human";
}
