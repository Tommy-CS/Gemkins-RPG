#include "Aetherion.h"
#include <iostream>
#include <string>

using namespace std;

// base stats: name(""), mysticCore(""), level(15), health(150), stamina(70), baseAttackPower(25), defensePower(10), speed(4)

// Constructor with base stats, move names, and move descriptions
Aetherion::Aetherion() : Gemkin("Aetherion, the Shard King", "Crystal/Dark", 15, 300, 70, 25, 10, 4) {
    setMaxHealth(150);
    setMaxStamina(70);

    setPhysicalMove("Shattered Strike");
    physicalMoveDesc = "A devastating physical attack that breaks the opponent's defenses with crystal shards.";

    setElementalMove("Dark Surge");
    elementalMoveDesc = "A massive wave of dark energy that engulfs the opponent, draining their vitality.";

    setBurstMove("Corrupting Crystals");
    burstMoveDesc = "A powerful surge of dark crystals pierces through the opponent.";
}

// Aetherion's physical move, base 30 damage
void Aetherion::usePhysicalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getPhysicalMove() << "! The opponent is impaled with devastating crystal shards" << endl;
    int attackPower = 30;
    // calculateDamage uses attackPower + baseAttackPower and the opponent's defense to get the final damage dealt (check main.cpp for details) applies to ALL functions below
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Aetherion's elemental move, base 38 damage
void Aetherion::useElementalMove(Gemkin* opponent) {
    cout << getName() << " uses " << getElementalMove() << "! A dark wave engulfs the opponent, draining their vitality." << endl;
    int attackPower = 38;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes " << damage << " damage!" << endl;
}

// Aetherion's burst move, base 50 damage
void Aetherion::useBurstMove(Gemkin* opponent) {
    cout << getName() << " uses " << getBurstMove() << "! A powerful surge of dark crystals pierces through the opponent." << endl;
    int attackPower = 50;
    int damage = calculateDamage(attackPower, opponent->getDefensePower());
    opponent->setHealth(opponent->getHealth() - damage);
    cout << opponent->getName() << " takes catastrophic damage! " << opponent->getName() << " is hit by relentless Corrupted Crystals, taking " << damage << " damage!" << endl;
}

// Aetherion's destructor
Aetherion::~Aetherion() {
    //cout << "Aetherion destructor called." << endl;
}
