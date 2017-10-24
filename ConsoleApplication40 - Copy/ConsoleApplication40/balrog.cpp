/*Myron Pow, CS2B, 7/21/15, Dave Harden, balrog.cpp
source file for balrog
*/

#include "demon.h"
#include "balrog.h"
#include "string"
#include <iostream>
using namespace std;




balrog::balrog()
{
    setHitpoints(10);
    setStrength(10);
}



balrog::balrog(int str, int hp)
    :demon (str, hp)
{
}




int balrog::getDamage()
{
    //cout << "The " << getSpecies() << " ";
    int damage = demon::getDamage();
    int damage2 = (rand() % getStrength()) + 1;
    cout << "Balrog speed attack inflicts "<< damage2 <<" additional damage points!" << endl;
    damage += damage2;
    return damage;
}




string balrog::getSpecies()
{
    return "balrog";
}