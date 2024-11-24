#include "PlayableGemkin.h"
#include <iostream>
#include <string>
#include <fstream>

PlayableGemkin::PlayableGemkin(string _name, string _mysticCore, int _level, int _health, int _stamina, int _baseAttackPower, int _defensePower, int _speed)
    : Gemkin(_name, _mysticCore, _level, _health, _stamina, _baseAttackPower, _defensePower, _speed), experience(0) {
}

void PlayableGemkin::setSupportMove(string newSupportMove) { supportMove = newSupportMove; }
string PlayableGemkin::getSupportMove() { return supportMove; }

int PlayableGemkin::getExperience() {return experience;}

// If you gain over 100 exp, you level up. When you level up, your stats will increase.
void PlayableGemkin::gainExperience(int newExperience) {
    experience += newExperience;

    // Level up while experience is >= 100
    while (experience >= 100) {
        level++;
        experience -= 100;
        cout << getName() << " leveled up to Level " << level << "!" << endl;

        // Increase stats since gemkin leveled up
        maxHealth += 10;       
        maxStamina += 2.5;       
        baseAttackPower += 1.5;  
        defensePower += 0.5;     

        // Sets Gemkin health and stamina to the new amount
        health = maxHealth;
        stamina = maxStamina;
 
        // Display updated stats
        cout << "Stats increased!" << endl;
        cout << "Health: " << maxHealth << ", Stamina: " << maxStamina << ", Attack Power: " << baseAttackPower << ", Defense Power: " << defensePower << endl;
    }
}

// If you go below 0 exp, you will lose a level
void PlayableGemkin::loseExperience(int newExperience) {
    if (experience - newExperience < 0) {
        if (level > 1) {
            level--;
            experience = 100 - (newExperience - experience);
        } else {
            experience = 0;
        }
    } else {
        experience -= newExperience;
    }
}

void PlayableGemkin::usePhysicalMove(Gemkin* opponent) {
    cout << "You used your physical move." << endl;
}

void PlayableGemkin::useElementalMove(Gemkin* opponent) {
    cout << "You used your elemental move." << endl;
}

void PlayableGemkin::useBurstMove(Gemkin* opponent) {
    cout << "You used your burst move." << endl;
}

void PlayableGemkin::useSupportMove() {
    cout << "You used your support move." << endl;
}

void PlayableGemkin::displayMoves() {
    cout << "You displayed your moves." << endl;
}

void PlayableGemkin::introduceGemkin() {
    cout << "You introduced your Gemkin." << endl;
}

// Function for saving information
void PlayableGemkin::saveToFile(string filename) {
    ofstream output(filename);
    if(output.is_open()) {
        cout << "Saving and exiting Gemkins... " << endl;

        // Each line is put into the output file, which can be loaded up as a previous save file.
        output << "Name: " << name << endl;
        output << "Mystic Core: " << mysticCore << endl;
        output << "Level: " << level << endl;
        output << "Experience: " << experience << endl;
        output << "Health: " << health << endl;
        output << "Stamina: " << stamina << endl;
        output << "Base Attack Power: " << baseAttackPower << endl;
        output << "Defense Power: " << defensePower << endl;
        output << "Speed: " << speed << endl;

        cout << "...Saving successful. Goodbye!" << endl;   
        output.close();
    }
    else {
        cout << "Output failed to open!" << endl; // 😨
        exit(1);
    }
}

void PlayableGemkin::loadSaveFile(string filename) {
    ifstream input(filename);

    // Checks if file failed to open
    if (!input.is_open()) {  
        cout << "Failed to open save file: " << filename << endl;
        exit(1);
    }

    // Plays if this file opened successfully
    cout << "Loading Gemkin data from save file: " << filename << "..." << endl;

    string temp;
    // Name
    if (getline(input, temp)) {
        name = temp.substr(6); // Starts at substr(6) cuz file starts from Name: _____. Same thing applies for everything below
        cout << "Loaded Name: " << name << endl;
    }

    // Mystic Core
    if (getline(input, temp)) {
        mysticCore = temp.substr(13);
        cout << "Loaded Mystic Core: " << mysticCore << endl;
    }

    // Level
    if (getline(input, temp)) {
        level = stoi(temp.substr(7));
        cout << "Loaded Level: " << level << endl;
    }

    // Experience
    if (getline(input, temp)) {
        experience = stoi(temp.substr(12));
        cout << "Loaded Experience: " << experience << endl;
    }

    // Health
    if (getline(input, temp)) {
        health = stoi(temp.substr(8));
        cout << "Loaded Health: " << health << endl;
        maxHealth = health; // Need this here or else the save will remember 100 as the maxHealth
    }

    // Stamina
    if (getline(input, temp)) {
        stamina = stoi(temp.substr(9));
        cout << "Loaded Stamina: " << stamina << endl;
        maxStamina = stamina; // Need this here or else the save will remember 100 as the maxStamina
    }

    // Base Attack Power
    if (getline(input, temp)) {
        baseAttackPower = stoi(temp.substr(19));
        cout << "Loaded Base Attack Power: " << baseAttackPower << endl;
    }

    // Defense Power
    if (getline(input, temp)) {
        defensePower = stoi(temp.substr(15));
        cout << "Loaded Defense Power: " << defensePower << endl;
    }

    // Speed
    if (getline(input, temp)) {
        speed = stoi(temp.substr(7));
        cout << "Loaded Speed: " << speed << endl;
    }

    cout << "Load successful. Gemkin data has been restored." << endl;
    input.close();
}

PlayableGemkin::~PlayableGemkin() {
    //cout << "PlayableGemkin destructor called." << endl;
}


