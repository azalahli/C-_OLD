/*Myron Pow, CS2B, 7/21/15, Dave Harden, cyberdemon.cpp
source file for cyberdemon
*/
#include "demon.h"
#include "cyberdemon.h"
#include "string"
#include <iostream>
using namespace std;




cyberdemon::cyberdemon()
{
    setHitpoints(10);
    setStrength(10);
}




cyberdemon::cyberdemon(int str, int hp)
    :demon (str, hp)
{
}

/*
int cyberdemon::getDamage()
{
    //cout << "The " << getSpecies() << " ";
    int damage = demon::getDamage();
    return damage;
}
*/


string cyberdemon::getSpecies()
{
    return "cyberdemon";
}