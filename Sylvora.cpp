#include "Sylvora.h"
#include <iostream>
#include <string>

using namespace std;

//Gemkin::Gemkin() : name(""), mysticCore(""), level(1), health(100), maxHealth(100), stamina(100), maxStamina(100), baseAttackPower(10), defensePower(5), speed(10), 

// Constructor with base stats, move names, and move descriptions
Sylvora::Sylvora() : PlayableGemkin("Sylvora", "Jade", 1, 105, 95, 13, 9, 6) {
    setMaxHealth(105);
    setMaxStamina(95);

    setPhysicalMove("Vine Lash");
    physicalMoveDesc = "Whips the opponent with sturdy vines.";

    setElementalMove("Verdant Bind");
    elementalMoveDesc = "Entangles the opponent in thick vines, with a chance of binding their movement.";

    setBurstMove("Nature's Wrath!");
    burstMoveDesc = "Unleashes the fury of nature, striking the opponenet with a storm of piercing thorns.";

    setSupportMove("Flourish");
    supportMoveDesc = "Harnesses the vitality of nature, restoring 15 Health and 10 Stamina.";
}

// Sylvora's physical move, base 13 damage
void Sylvora::usePhysicalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getPhysicalMove() << "! Vines whip the opponent." << endl;
    int moveAttackPower = 13;
    // calculateDamage uses attackPower + baseAttackPower and the opponent's defense to get the final damage dealt (check main.cpp for details) applies to ALL functions below
    int damage = calculateDamage(moveAttackPower, opponent->getDefensePower()); 
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Sylvora's elemental move, base 20 damage
void Sylvora::useElementalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getElementalMove() << "! The opponent is entangled in vines." << endl;
    int attackPower = 19;
    int damage = calculateDamage(attackPower, opponent->getDefensePower()); 
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " is bound by vines and takes " << damage << " damage!" << endl;
}

// Sylvora's burst move, base 35 damage
void Sylvora::useBurstMove(Gemkin* opponent) {
    cout << getName() << " uses Nature's Wrath! A storm of thorns descends upon the opponent." << endl;
    int baseAttack = 34;

    int damage = calculateDamage(baseAttack, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " is hit by a devastating attack! " << opponent->getName() << " is bombarded by the thorny barrage, taking " << damage << " damage!" << endl;
}

// Sylvora's support move, heals you by 15 HP and gain 10 stamina
void Sylvora::useSupportMove() {
    cout << getName() << " uses " << getSupportMove() << "! " << supportMoveDesc << endl;
    int restoredHealth = min(getHealth() + 15, getMaxHealth());
    int restoredStamina = min(getStamina() + 10, getMaxStamina());
    setHealth(restoredHealth);
    setStamina(restoredStamina);
    cout << getName() << "'s health is now " << getHealth() << " and stamina is now " << getStamina() << "!" << endl;
}

// Introduces basic information and stats of Sylvora
void Sylvora::introduceGemkin() {
    cout << getName() << " has a " << getMysticCore() << " mystic core (Nature). "
         << getName() << "'s stats include: Level " << getLevel() << ", Health " << getHealth()
         << ", Stamina " << getStamina() << "." << endl;
}

// Displays Sylvora's exclusive moves, stamina costs (same for everyone) and move descriptions
void Sylvora::displayMoves() {
    cout << getName() << "'s moves:" << endl;
    cout << "1. Physical Move: " << getPhysicalMove() << " (-10 Stamina) - " << physicalMoveDesc << endl;
    cout << "2. Elemental Move: " << getElementalMove() << " (-20 Stamina) - " << elementalMoveDesc << endl;
    cout << "3. Burst Move: " << getBurstMove() << " (-40 Stamina) - " << burstMoveDesc << endl;
    cout << "4. Support Move: " << getSupportMove() << " (+15 Health, +10 Stamina) - " << supportMoveDesc << endl;
}

// Sylvora's destructor
Sylvora::~Sylvora() {
    //cout << "Sylvora destructor called." << endl;
}
