#include "Igneel.h"
#include <iostream>
#include <string>

using namespace std;

//Gemkin::Gemkin() : name(""), mysticCore(""), level(1), health(100), maxHealth(100), stamina(100), maxStamina(100), baseAttackPower(10), defensePower(5), speed(10), 

// Constructor with base stats, move names, and move descriptions
Igneel::Igneel() : PlayableGemkin("Igneel", "Sunstone/Onyx", 1, 100, 90, 15, 8, 7) { //, Playable() {
    setMaxHealth(100);
    setMaxStamina(90);

    setPhysicalMove("Ember Fang");
    physicalMoveDesc = "A fierce bite charged with fiery energy.";
    
    setElementalMove("Flame Breath");
    elementalMoveDesc = "Releases a small flame from its mouth to scorch the opponent.";
    
    setBurstMove("Scorching Aura");
    burstMoveDesc = "Surrounds Igneel in a fiery aura that burns the opponent.";
    
    setSupportMove("Ember Recharge");
    supportMoveDesc = "Igneel harnesses his inner flames to restore 15 Health and 10 Stamina.";
}

// Igneel's physical move, base 15 damage
void Igneel::usePhysicalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getPhysicalMove() << "! A fiery bite strikes the opponent." << endl;
    int attackPower = 15;
    // calculateDamage uses attackPower + baseAttackPower and the opponent's defense to get the final damage dealt (check main.cpp for details) applies to ALL functions below
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Igneel's elemental move, base 20 damage
void Igneel::useElementalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getElementalMove() << "! Flames engulf the opponent." << endl;
    int attackPower = 20;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Igneel's burst move, base 35 damage
void Igneel::useBurstMove(Gemkin* opponent) {
    cout << getName() << " unleashes " << getBurstMove() << "! The opponent is severely scorched by the aura!" << endl;
    int attackPower = 35;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    // All burst attacks say "hit by a devastating attack"
    cout << opponent->getName() << " is hit by a devastating attack and takes " << damage << " damage!" << endl;
}

// Igneel's support move, heals you by 15 HP and gain 10 stamina
void Igneel::useSupportMove() {
    cout << getName() << " uses " << getSupportMove() << "! " << supportMoveDesc << endl;
    int restoredHealth = min(getHealth() + 15, getMaxHealth());
    int restoredStamina = min(getStamina() + 10, getMaxStamina());
    setHealth(restoredHealth);
    setStamina(restoredStamina);
    cout << getName() << "'s health is now " << getHealth() << " and stamina is now " << getStamina() << "!" << endl;
}

// Introduces basic information and stats of Igneel
void Igneel::introduceGemkin() {
    cout << getName() << " has a " << getMysticCore() << " mystic core (Fire/Dragon). " 
         << getName() << "'s stats include: Level " << getLevel() << ", Health " << getHealth() 
         << ", Stamina " << getStamina() << "." << endl;
}

// Displays Igneel's exclusive moves, stamina costs (same for everyone) and move descriptions
void Igneel::displayMoves() {
    cout << getName() << "'s moves:" << endl;
    cout << "1. Physical Move: " << getPhysicalMove() << " (-10 Stamina) - " << physicalMoveDesc << endl;
    cout << "2. Elemental Move: " << getElementalMove() << " (-20 Stamina) - " << elementalMoveDesc << endl;
    cout << "3. Burst Move: " << getBurstMove() << " (-40 Stamina) - " << burstMoveDesc << endl;
    cout << "4. Support Move: " << getSupportMove() << " (+15 Health, +10 Stamina) - " << supportMoveDesc << endl;
}

// Igneel's destructor
Igneel::~Igneel() {
    //cout << "Igneel destructor called." << endl;
}
