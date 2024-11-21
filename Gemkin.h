#pragma once

#include <iostream>
#include <string>

using namespace std;

// This is the base class
class Gemkin {
public:
    Gemkin(); 

    Gemkin(string _name, string _mysticCore, int _level, int _health, int _stamina, int _baseAttackPower, int _defensePower, int _speed) : 
            name(_name), mysticCore(_mysticCore), level(1), health(_health), maxHealth(_health), stamina(_stamina), maxStamina(_stamina), 
            baseAttackPower(_baseAttackPower), defensePower(_defensePower), speed(_speed) {}; 

    // Getters
    string getName() { return name; }
    string getMysticCore() { return mysticCore; }
    int getHealth() { return health; }
    int getMaxHealth() { return maxHealth; }
    int getStamina() { return stamina; }
    int getMaxStamina() { return maxStamina; }
    int getSpeed() { return speed; }
    int getLevel() { return level; }
    int getBaseAttackPower() { return baseAttackPower; }
    int getMoveAttackPower() { return moveAttackPower; }
    int getDefensePower() { return defensePower; }
    string getPhysicalMove() { return physicalMove; }
    string getElementalMove() { return elementalMove; }
    string getBurstMove() { return burstMove; }

    // Setters
    void setHealth(int newHealth) { health = newHealth; }
    void setMaxHealth(int maxHP) { maxHealth = maxHP; }
    void setStamina(int newStamina) { stamina = newStamina; }
    void setMaxStamina(int maxStam) { maxStamina = maxStam; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
    void setLevel(int newLevel) { level = newLevel; }
    void setBaseAttackPower(int newBaseAttackPower) { baseAttackPower = newBaseAttackPower; }
    virtual void setMoveAttackPower(int newMoveAttackPower) { moveAttackPower = newMoveAttackPower; }
    void setDefensePower(int newDefensePower) { defensePower = newDefensePower; }
    void setPhysicalMove(string newPhysicalMove) { physicalMove = newPhysicalMove; }
    virtual void setElementalMove(string newElementalMove) { elementalMove = newElementalMove; }
    void setBurstMove(string newBurstMove) { burstMove = newBurstMove; }

    // Other methods
    virtual void usePhysicalMove(Gemkin* opponent) = 0; //might need to change the pointer type...
    virtual void useElementalMove(Gemkin* opponent) = 0;
    virtual void useBurstMove(Gemkin* opponent) = 0;

    // Calculate damage by adding moveAttackPower + baseAttackPower, taking into account defense
    int calculateDamage(int moveAttackPower, int opponentDefensePower) {
        int rawDamage = baseAttackPower + moveAttackPower;
        int effectiveDamage = rawDamage - (opponentDefensePower / 2);
        return effectiveDamage;
    };

    void saveToFile(string filename);
    void loadSaveFile(string filename);

    ~Gemkin() {
        //cout << "Gemkin destructor called." << endl; // Comment out later
    };

protected:
    string name;
    string mysticCore;
    int health;
    int maxHealth;
    int stamina;
    int maxStamina;
    int speed;
    int level;
    int baseAttackPower;
    int moveAttackPower;
    int defensePower;
    string physicalMove;
    string elementalMove;
    string burstMove;
};
