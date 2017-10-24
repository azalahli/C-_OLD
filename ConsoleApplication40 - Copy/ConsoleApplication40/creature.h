/*Myron Pow, CS2B, 7/21/15, Dave Harden, creature.h
header file for creature
*/
#include <string>
#ifndef Creature
#define Creature

class creature
{
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain
public:
creature();
creature(int newStrength, int newHit);
// Initialize creature to new type, strength, hit points
// Also add appropriate accessor and mutator functions
// for type, strength, and hit points
virtual int getDamage();
// Returns amount of damage this creature
// inflicts in one round of combat
virtual std::string getSpecies() = 0; // Returns type of species

int getStrength();
int getHitpoints();

void setStrength(int str);
void setHitpoints(int hp);

};
#endif