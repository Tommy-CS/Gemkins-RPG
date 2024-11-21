#include "Cryonox.h"
#include <iostream>
#include <string>

using namespace std;

//Gemkin::Gemkin() : name(""), mysticCore(""), level(1), health(100), maxHealth(100), stamina(100), maxStamina(100), baseAttackPower(10), defensePower(5), speed(10), 

// Constructor with base stats, move names, and move descriptions
Cryonox::Cryonox() : PlayableGemkin("Cryonox", "Aquamarine/Moonstone", 1, 110, 110, 12, 10, 5) {
    setMaxHealth(110);
    setMaxStamina(110);

    setPhysicalMove("Frost Strike");
    physicalMoveDesc = "A sharp, freezing blow that strikes with the chill of ice.";

    setElementalMove("Glacial Surge");
    elementalMoveDesc = "Unleashes a powerful torrent of icy water that crashes into the opponent.";

    setBurstMove("Absolute Zero");
    burstMoveDesc = "Unleashes the pure essence of ice, dealing devastating frost damage to all in its path.";

    setSupportMove("Winter's Embrace");
    supportMoveDesc = "Cryonox forms a protective ice bubble around itself, restoring 15 Health and 10 Stamina.";
}

// Cryonox's physical move, base 12 damage
void Cryonox::usePhysicalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getPhysicalMove() << "! A chilling strike hits the opponent." << endl;
    int attackPower = 12;
    // calculateDamage uses attackPower + baseAttackPower and the opponent's defense to get the final damage dealt (check main.cpp for details) applies to ALL functions below
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Cryonox's elemental move, base 20 damage
void Cryonox::useElementalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getElementalMove() << "! A surge of icy water engulfs the opponent." << endl;
    int attackPower = 17;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Cryonox's burst move, base 35 damage
void Cryonox::useBurstMove(Gemkin* opponent) {
    cout << getName() << " unleashes " << getBurstMove() << "! Devastating frost damage overwhelms the opponent!" << endl;
    int attackPower = 32;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " is hit by a devastating attack! " << opponent->getName() << " is engulfed in absolute frost, suffering " << damage << " damage!" << endl;
}

// Cryonox's support move, heals you by 15 HP and gain 10 stamina
void Cryonox::useSupportMove() {
    cout << getName() << " uses " << getSupportMove() << "! " << supportMoveDesc << endl;
    int restoredHealth = min(getHealth() + 15, getMaxHealth());
    int restoredStamina = min(getStamina() + 10, getMaxStamina());
    setHealth(restoredHealth);
    setStamina(restoredStamina);
    cout << getName() << "'s health is now " << getHealth() << " and stamina is now " << getStamina() << "!" << endl;
}

// Introduces basic information and stats of Cryonox
void Cryonox::introduceGemkin() {
    cout << getName() << " has a " << getMysticCore() << " mystic core (Ice/Water). " 
         << getName() << "'s stats include: Level " << getLevel() << ", Health " << getHealth() 
         << ", Stamina " << getStamina() << "." << endl;
}

// Displays Cryonox's exclusive moves, stamina costs (same for everyone) and move descriptions
void Cryonox::displayMoves() {
    cout << getName() << "'s moves:" << endl;
    cout << "1. Physical Move: " << getPhysicalMove() << " (-10 Stamina) - " << physicalMoveDesc << endl;
    cout << "2. Elemental Move: " << getElementalMove() << " (-20 Stamina) - " << elementalMoveDesc << endl;
    cout << "3. Burst Move: " << getBurstMove() << " (-40 Stamina) - " << burstMoveDesc << endl;
    cout << "4. Support Move: " << getSupportMove() << " (+15 Health, +10 Stamina) - " << supportMoveDesc << endl;
}

// Cryonox's destructor
Cryonox::~Cryonox() {
    //cout << "Cryonox destructor called." << endl;
}
