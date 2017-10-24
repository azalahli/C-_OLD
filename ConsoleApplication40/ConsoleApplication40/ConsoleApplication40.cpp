/*Myron Pow, CS2B, 7/21/15, Dave Harden, ConsoleApplication40.cpp
Client file for creatures
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

using namespace std;



int main() {
	srand(time(0));
	
	human h1;
	elf e1;
	cyberdemon c1;
	balrog b1;
	
	human h(20, 30);
	elf e(40, 50);
	cyberdemon c(60, 70);
	balrog b(80, 90);

	
	cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
	cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
	cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
	cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
	cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
	cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
	cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
	cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
	cout << endl << endl;

	cout << "Examples of " << h.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = h.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
	
	
	
	cout << "Examples of " << e.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = e.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
	
	
	
	cout << "Examples of " << c.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = c.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
	
	
	
	cout << "Examples of " << b.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = b.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
}

/*RUN
default human strength/hitpoints: 10/10
default elf strength/hitpoints: 10/10
default cyberdemon strength/hitpoints: 10/10
default balrog strength/hitpoints: 10/10
non-default human strength/hitpoints: 20/30
non-default elf strength/hitpoints: 40/50
non-default cyberdemon strength/hitpoints: 60/70
non-default balrog strength/hitpoints: 80/90


Examples of human damage:
The human attacks for 5 points!
 Total damage = 5

The human attacks for 20 points!
 Total damage = 20

The human attacks for 1 points!
 Total damage = 1

The human attacks for 10 points!
 Total damage = 10

The human attacks for 19 points!
 Total damage = 19

The human attacks for 17 points!
 Total damage = 17

The human attacks for 19 points!
 Total damage = 19

The human attacks for 18 points!
 Total damage = 18

The human attacks for 6 points!
 Total damage = 6

The human attacks for 6 points!
 Total damage = 6


Examples of elf damage:
The elf attacks for 9 points!
Magical attack inflicts 9 additional damage points!
 Total damage = 18

The elf attacks for 27 points!
 Total damage = 27

The elf attacks for 30 points!
 Total damage = 30

The elf attacks for 8 points!
Magical attack inflicts 8 additional damage points!
 Total damage = 16

The elf attacks for 34 points!
 Total damage = 34

The elf attacks for 10 points!
 Total damage = 10

The elf attacks for 14 points!
Magical attack inflicts 14 additional damage points!
 Total damage = 28

The elf attacks for 35 points!
 Total damage = 35

The elf attacks for 24 points!
 Total damage = 24

The elf attacks for 29 points!
Magical attack inflicts 29 additional damage points!
 Total damage = 58


Examples of cyberdemon damage:
The cyberdemon  attacks for 43 points!
 Total damage = 43

The cyberdemon  attacks for 26 points!
 Total damage = 26

The cyberdemon  attacks for 59 points!
 Total damage = 59

The cyberdemon  attacks for 48 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 98

The cyberdemon  attacks for 48 points!
 Total damage = 48

The cyberdemon  attacks for 18 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 68

The cyberdemon  attacks for 57 points!
 Total damage = 57

The cyberdemon  attacks for 7 points!
 Total damage = 7

The cyberdemon  attacks for 47 points!
 Total damage = 47

The cyberdemon  attacks for 54 points!
 Total damage = 54


Examples of balrog damage:
The balrog  attacks for 31 points!
Balrog speed attack inflicts 11 additional damage points!
 Total damage = 42

The balrog  attacks for 9 points!
Balrog speed attack inflicts 73 additional damage points!
 Total damage = 82

The balrog  attacks for 78 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 53 additional damage points!
 Total damage = 181

The balrog  attacks for 38 points!
Balrog speed attack inflicts 76 additional damage points!
 Total damage = 114

The balrog  attacks for 11 points!
Balrog speed attack inflicts 47 additional damage points!
 Total damage = 58

The balrog  attacks for 64 points!
Balrog speed attack inflicts 45 additional damage points!
 Total damage = 109

The balrog  attacks for 46 points!
Balrog speed attack inflicts 12 additional damage points!
 Total damage = 58

The balrog  attacks for 70 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 76 additional damage points!
 Total damage = 196

The balrog  attacks for 36 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 6 additional damage points!
 Total damage = 92

The balrog  attacks for 78 points!
Balrog speed attack inflicts 27 additional damage points!
 Total damage = 105


Press any key to continue . . ..
*/