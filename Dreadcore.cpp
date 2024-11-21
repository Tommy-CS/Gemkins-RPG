#include "Dreadcore.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

using namespace std;

// Constructor with base stats, move names, and move descriptions
Dreadcore::Dreadcore(int originalLevel) : Gemkin("Dreadcore", "Shadow/Corruption", originalLevel, 100, 100, 10, 8, 6) {
    // Randomized stats to make the experience fun 😈
    srand(time(0)); 
    int dreadCoreLevel = originalLevel + (rand() % 4);  // Sets dreadcore's level to Gemkin's level + 0-3 levels
    setLevel(dreadCoreLevel);
    randHealth = (dreadCoreLevel * 9) + 85;             // Each level up is +9 HP + 85 base HP         
    setHealth(randHealth);
    setMaxHealth(randHealth);
    randStamina = (dreadCoreLevel * 4) + 50;            // Each level up is +4 stamina + 50 base stamina        
    setStamina(randStamina);
    setMaxStamina(randStamina);
    setBaseAttackPower((dreadCoreLevel * 1.5) + 3);     // Each level up is +1.5 base atk pwr +3 base atk pwr     
    setDefensePower((rand() % 6) + 5);                  // Random num between 5-10      
    setSpeed((rand() % 13) + 4);                        // Random num between 4-12            

    setPhysicalMove("Shadow Claw");
    physicalMoveDesc = "Slashes with claws infused with dark energy, leaving a lingering corruption.";

    setElementalMove("Dark Pulse");
    elementalMoveDesc = "Unleashes a wave of shadowy energy that engulfs the opponent.";

    setBurstMove("Corrupting Aura");
    burstMoveDesc = "Emanates a dark aura that drains the opponent's health over time, giving it to itself.";
}

// Dreadcore's physical move, base 12 dmg
void Dreadcore::usePhysicalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getPhysicalMove() << "! Corruption fills the wound of your opponent." << endl;
    int attackPower = 12;
    // calculateDamage uses attackPower + baseAttackPower and the opponent's defense to get the final damage dealt (check main.cpp for details) applies to ALL functions below
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Dreadcore's elemental move, base 20 dmg
void Dreadcore::useElementalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getElementalMove() << "! The opponent is engulfed in shadowy energy." << endl;
    int attackPower = 20;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Dreadcore's burst move, deals base 15 damage. The final caclulated damage dealt is added to its HP (lifesteel basically)
void Dreadcore::useBurstMove(Gemkin* opponent) {
    cout << getName() << " uses " << getBurstMove() << "! The opponent's life energy is being absorbed." << endl;
    int baseDrain = 15;
    int drainAmount = static_cast<int>(baseDrain * (1 + getLevel() * 0.03)); // Adjust the value if it's too op, scales off of level
    opponent->setHealth(opponent->getHealth() - drainAmount);
    setHealth(getHealth() + drainAmount);
    cout << opponent->getName() << " takes " << drainAmount << " damage, and " << getName() << " restores " << drainAmount << " health!" << endl;
}

// Implement Dreadcore's specific support move
/*
void Dreadcore::useSupportMove() {
    cout << getName() << " uses " << getSupportMove() << "! Dreadcore's defense increases." << endl;
    int defenseBoost = 4 + (getLevel() / 2);
    setDefensePower(getDefensePower() + defenseBoost);
    cout << getName() << "'s defense power is now " << getDefensePower() << "!" << endl;
}
*/

// Dreadcore's destructor
Dreadcore::~Dreadcore() {
    //cout << "Dreadcore destructor called." << endl;
}