/*Myron Pow, CS2B, 7/21/15, Dave Harden, demon.cpp
source file for demon
*/
#include "creature.h"
#include "demon.h"
#include "string"
#include <iostream>
using namespace std;

const int demonAttack = 25; // % chance to deal bonus damage
const int bonusDamage = 50; // Bonus damage





demon::demon()
{
    setHitpoints(10);
    setStrength(10);
}



demon::demon(int str, int hp)
    :creature (str, hp)
{
}




int demon::getDamage()
{
    int damage = creature::getDamage();
    int crit = (rand() % 100) + 1;
    cout << " attacks for " << damage << " points!"
        << endl;
    if (crit <= demonAttack)
    {
        cout << "Demonic attack inflicts " << bonusDamage << " additional damage points!"
            << endl;
        damage += bonusDamage;
    }
    return damage;
}




string demon::getSpecies()
{
    return "demon";
}