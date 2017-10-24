/*Myron Pow, CS2B, 7/21/15, Dave Harden, ConsoleApplication40.cpp
Client file for creatures and derivatives
*/

#include "balrog.h"
#include "cyberdemon.h"
#include "demon.h"
#include "elf.h"
#include "creature.h"
#include "human.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void battleArena(creature &creature1, creature &creature2);
using namespace std;

int main()
{
	srand((time(0)));

	elf e(50,50);
	balrog b(3000,200);
    elf a (50, 50);
    human food(1, 1000);
    human hero(1000, 10);
    elf murder(10000, 500);
    cyberdemon peace(1, 1000000);
    cyberdemon war(1000000, 1);
    balrog gandalf(1000, 20);


    battleArena(e, b);
    battleArena(food, a);
    battleArena(hero, b);
    battleArena(peace, hero);
    battleArena(war, peace);
    battleArena(gandalf, food);
    battleArena(gandalf, murder);
}

void battleArena(creature &creature1, creature &creature2)
{
    cout << "PREPARE FOR BATTLE!" << endl;
    cout << "Contestant 1: " << creature1.getSpecies() << endl;
    cout << "Contestant 2: " << creature2.getSpecies() << endl;
    int creature1HP;
    int creature2HP;
    int roundcounter = 0;
    creature1HP = creature1.getHitpoints();
    creature2HP = creature2.getHitpoints();
    while ((creature1HP >= 0) && (creature2HP >= 0))
    {
        cout << endl;
        cout << "Contestant 1 Attacks!" << endl;
        creature2HP -= creature1.getDamage();
        cout << "Contestant 2 Attacks!" << endl;
        creature1HP -= creature2.getDamage();
        cout << "End of Round " << ++roundcounter << endl;
    }
    cout << endl;
    if ((creature1HP <= 0) && (creature2HP <= 0))
        cout << "Tie!" << endl;
    else if (creature1HP <= 0)
        cout << "Contestant 2: " << creature2.getSpecies() 
        << " has won the battle!" << endl;
    else if (creature2HP <= 0)
        cout << "Contestant 1: " << creature1.getSpecies() 
        << " has won the battle!" << endl;
    cout << endl;
    return;
}

/* RUN
PREPARE FOR BATTLE!
Contestant 1: elf
Contestant 2: balrog

Contestant 1 Attacks!
The elf attacks for 20 points!
Contestant 2 Attacks!
The balrog attacks for 716 points!
Balrog speed attack inflicts 1040 additional damage points!
End of Round 1

Contestant 2: balrog has won the battle!

PREPARE FOR BATTLE!
Contestant 1: human
Contestant 2: elf

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 35 points!
End of Round 1

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 30 points!
Magical attack inflicts 30 additional damage points!
End of Round 2

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 9 points!
Magical attack inflicts 9 additional damage points!
End of Round 3

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 45 points!
Magical attack inflicts 45 additional damage points!
End of Round 4

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 21 points!
Magical attack inflicts 21 additional damage points!
End of Round 5

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 34 points!
Magical attack inflicts 34 additional damage points!
End of Round 6

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 3 points!
End of Round 7

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 45 points!
Magical attack inflicts 45 additional damage points!
End of Round 8

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 38 points!
Magical attack inflicts 38 additional damage points!
End of Round 9

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 16 points!
Magical attack inflicts 16 additional damage points!
End of Round 10

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 49 points!
End of Round 11

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 19 points!
Magical attack inflicts 19 additional damage points!
End of Round 12

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 36 points!
Magical attack inflicts 36 additional damage points!
End of Round 13

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 46 points!
End of Round 14

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 23 points!
Magical attack inflicts 23 additional damage points!
End of Round 15

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 13 points!
End of Round 16

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 48 points!
Magical attack inflicts 48 additional damage points!
End of Round 17

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 18 points!
End of Round 18

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 44 points!
End of Round 19

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 18 points!
End of Round 20

Contestant 1 Attacks!
The human attacks for 1 points!
Contestant 2 Attacks!
The elf attacks for 27 points!
Magical attack inflicts 27 additional damage points!
End of Round 21

Contestant 2: elf has won the battle!

PREPARE FOR BATTLE!
Contestant 1: human
Contestant 2: balrog

Contestant 1 Attacks!
The human attacks for 575 points!
Contestant 2 Attacks!
The balrog attacks for 1912 points!
Balrog speed attack inflicts 1696 additional damage points!
End of Round 1

Tie!

PREPARE FOR BATTLE!
Contestant 1: cyberdemon
Contestant 2: human

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 170 points!
End of Round 1

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 570 points!
End of Round 2

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 240 points!
End of Round 3

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 956 points!
End of Round 4

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 377 points!
End of Round 5

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Contestant 2 Attacks!
The human attacks for 178 points!
End of Round 6

Contestant 1 Attacks!
The cyberdemon attacks for 1 points!
Demonic attack inflicts 50 additional damage points!
Contestant 2 Attacks!
The human attacks for 753 points!
End of Round 7

Contestant 1: cyberdemon has won the battle!

PREPARE FOR BATTLE!
Contestant 1: cyberdemon
Contestant 2: cyberdemon

Contestant 1 Attacks!
The cyberdemon attacks for 21102 points!
Demonic attack inflicts 50 additional damage points!
Contestant 2 Attacks!
The cyberdemon attacks for 1 points!
End of Round 1

Contestant 1 Attacks!
The cyberdemon attacks for 457 points!
Contestant 2 Attacks!
The cyberdemon attacks for 1 points!
End of Round 2

Contestant 2: cyberdemon has won the battle!

PREPARE FOR BATTLE!
Contestant 1: balrog
Contestant 2: human

Contestant 1 Attacks!
The balrog attacks for 105 points!
Balrog speed attack inflicts 273 additional damage points!
Contestant 2 Attacks!
The human attacks for 1 points!
End of Round 1

Contestant 1 Attacks!
The balrog attacks for 809 points!
Balrog speed attack inflicts 560 additional damage points!
Contestant 2 Attacks!
The human attacks for 1 points!
End of Round 2

Contestant 1: balrog has won the battle!

PREPARE FOR BATTLE!
Contestant 1: balrog
Contestant 2: elf

Contestant 1 Attacks!
The balrog attacks for 9 points!
Balrog speed attack inflicts 389 additional damage points!
Contestant 2 Attacks!
The elf attacks for 8401 points!
End of Round 1

Contestant 2: elf has won the battle!

Press any key to continue . . .
*/