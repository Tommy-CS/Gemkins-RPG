#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Igneel.h"
#include "Cryonox.h"
#include "Sylvora.h"
#include "Dreadcore.h"
#include "Aetherion.h"

#include "Rungame.h"
#include <thread>
#include <chrono>

using namespace std;

PlayableGemkin* gemkinPtr = nullptr;
void lore() {
    cout << "Would you like to listen to the lore of this game? Please enter [yes] or [no]" << endl;
    string userInput = "";
    cin >> userInput;
    // Ensures a valid input is taken
    while ((userInput != "yes") && (userInput != "no")) {
        cout << "Please enter a valid response." << endl;
        cin >> userInput;
    }
    if (userInput == "no") {
        cout << "Understood. Skipping lore." << endl; 
    }
    else if (userInput == "yes") {
        fullIntroLore();
    }
}
// Introduce the starter Gemkins and the player selects which one they want to raise.
void introduceStarters() {
    startersDialgue();
    char chosenGemkin;
    cin >> chosenGemkin;
    // Ensures a valid answer is put in
    while ((chosenGemkin != 'i') && (chosenGemkin != 'c') && (chosenGemkin != 's')) {
        cout << "Please enter a valid response. Enter (i), (c), or (s)." << endl;
        cin >> chosenGemkin;
    }
    // Creates a gemkinPtr of the chosen gemkin
    if (chosenGemkin == 'i') {
        gemkinPtr = new Igneel();
        cout << "Fantastic choice. Igneel's fiery spirit will blaze a path through any darkness." << endl;
    }
    else if (chosenGemkin == 'c') { 
        gemkinPtr = new Cryonox();
        cout << "A wise choice. Cryonox's calm and icy resolve will be invaluable in the battles ahead." << endl;
    }
    else if (chosenGemkin == 's') { 
        gemkinPtr = new Sylvora();
        cout << "An excellent pick. Sylvora's connection to nature will empower you in unexpected ways." << endl;
    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Now set forth on your journey!" << endl;
    cout << "TIP: You should level up your Gemkins, so head to the wilderness and get to fighting!" << endl;
}

// Enter the wilderness to fight Dreadcores | OPTION 1
void enterCombat() {
    int originalLevel = gemkinPtr->getLevel();
    Gemkin* dreadcorePtr = new Dreadcore(originalLevel);
    cout << gemkinPtr->getName() << " encounters a fearsome Dreadcore!" << endl;

    cout << gemkinPtr->getName() << "'s health: " << gemkinPtr->getHealth() << endl;
    cout << gemkinPtr->getName() << "'s level: " << gemkinPtr->getLevel() << endl;

    cout << dreadcorePtr->getName() << "'s health: " << dreadcorePtr->getHealth() << endl;
    cout << dreadcorePtr->getName() << "'s level: " << dreadcorePtr->getLevel() << endl;

    // Determine who goes first based on speed (highest speed goes first)
    bool playerTurn = gemkinPtr->getSpeed() >= dreadcorePtr->getSpeed();

    while (gemkinPtr->getHealth() > 0 && dreadcorePtr->getHealth() > 0) {
        if (playerTurn) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << gemkinPtr->getName() << "'s turn!" << endl;
            cout << gemkinPtr->getName() << "'s health: " << gemkinPtr->getHealth() << endl;
            cout << gemkinPtr->getName() << "'s stamina: " << gemkinPtr->getStamina() << endl;
            gemkinPtr->displayMoves();
            int choice;
            cin >> choice;

            while (choice < 1 || choice > 4) {
                cout << "Not a valid option. Please try again." << endl;
                cin >> choice;
            }

            switch (choice) {
                case 1: // Gemkin's physical move
                    if (gemkinPtr->getStamina() >= 10) {
                        gemkinPtr->usePhysicalMove(dreadcorePtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 10);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 2: // Gemkin's elemental move
                    if (gemkinPtr->getStamina() >= 20) {
                        gemkinPtr->useElementalMove(dreadcorePtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 20);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 3: // Gemkin's burst move
                    if (gemkinPtr->getStamina() >= 40) {
                        gemkinPtr->useBurstMove(dreadcorePtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 40);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 4:
                    gemkinPtr->useSupportMove();
                    
            }

            cout << "Dreadcore health: " << max(dreadcorePtr->getHealth(), 0) << endl;
            cout << "Dreadcore stamina: " << max(dreadcorePtr->getStamina(), 0) << endl;
        } else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Dreadcore's turn!" << endl;

            int dreadcoreMove = rand() % 3;
            switch (dreadcoreMove) {
                case 0:
                    if (dreadcorePtr->getStamina() >= 10) {
                        dreadcorePtr->usePhysicalMove(gemkinPtr);
                        dreadcorePtr->setStamina(dreadcorePtr->getStamina() - 10);
                    } else {
                        cout << "Dreadcore used Shadow Claw! Dreadcore missed." << endl;
                    }
                    break;
                case 1:
                    if (dreadcorePtr->getStamina() >= 20) {
                        dreadcorePtr->useElementalMove(gemkinPtr);
                        dreadcorePtr->setStamina(dreadcorePtr->getStamina() - 20);
                    } else {
                        cout << "Dreadcore used Dark Pulse! Dreadcore missed." << endl;
                    }
                    break;
                case 2:
                    if (dreadcorePtr->getStamina() >= 40) {
                        dreadcorePtr->useBurstMove(gemkinPtr);
                        dreadcorePtr->setStamina(dreadcorePtr->getStamina() - 40);
                    } else {
                        cout << "Dreadcore used Corrupting Aura! Dreadcore missed." << endl;
                    }
                    break;
            }
        }

        // Stamina regeneration without them going past their max amounts
        gemkinPtr->setStamina(min(gemkinPtr->getStamina() + 5, gemkinPtr->getMaxStamina()));
        dreadcorePtr->setStamina(min(dreadcorePtr->getStamina() + 5, dreadcorePtr->getMaxStamina()));

        // Check if health reaches zero
        if (gemkinPtr->getHealth() <= 0) {
            int experienceLoss = (rand() % 31) + 20; // You will lose minimum 20 exp + a random num from 1-30
            cout << "Oh no! " << gemkinPtr->getName() << " has been defeated!" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "A voice commands you to get up... Destiny prevents " << gemkinPtr->getName() << "'s death. " << gemkinPtr->getName() << " has been revived with low health and stamina." << endl;
            gemkinPtr->setHealth(20);
            gemkinPtr->setStamina(20);
            gemkinPtr->loseExperience(experienceLoss);
            cout << "You lost " << experienceLoss << " experience." << endl;
            cout << gemkinPtr->getName() << "'s level: " << gemkinPtr->getLevel() << endl;
            cout << gemkinPtr->getName() << "'s experience: " << gemkinPtr->getExperience() << "/100" << endl;
            cout << "TIP: You should head to the Healing Center to recover health and stamina." << endl;
            break;
        } else if (dreadcorePtr->getHealth() <= 0) {
            int experienceGain = (rand() % 31) + 50; // You will gain minimum 50 exp + 1-30 more exp
            //int experienceGain = 1950; // for testing purposes, gets you to level 20 w/ 50 exp
            cout << "Congratulations! You defeated the Dreadcore!" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            gemkinPtr->gainExperience(experienceGain);
            cout << "You gained " << experienceGain << " experience." << endl;
            cout << gemkinPtr->getName() << "'s level: " << gemkinPtr->getLevel() << endl;
            cout << gemkinPtr->getName() << "'s experience: " << gemkinPtr->getExperience() << "/100"<< endl;
            cout << "TIP: You should head to the Healing Center to recover health and stamina." << endl;
            break;
        }

        playerTurn = !playerTurn;
    }

    delete dreadcorePtr;
}

// Heal your Gemkin here | OPTION 2
void healingCenter() {
    cout << "Heading to the Healing Center..." << endl;
    healingCenterPic();
    cout << "Welcome, traveler! I see your Gemkin has been through some battles. Let me restore its vitality." << endl;
    gemkinPtr->setHealth(gemkinPtr->getMaxHealth());
    gemkinPtr->setStamina(gemkinPtr->getMaxStamina());
    cout << ". . ." << endl;
    this_thread::sleep_for(chrono::seconds(4));
    cout << gemkinPtr->getName() << " has been FULLY restored!" << endl;
    cout << "Goodbye!" << endl;

}


// The ending dialogue for the game w/ plot twist, exits the game after dialogue is complete.
void theEnd() {
    endingDialogue();
    delete gemkinPtr;
    exit(0);
}

// Boss battle!! | OPTION 3
void bossBattle() {
    // Dialogue introduction for the boss battle
    bossDialogue();

    Gemkin* aetherionPtr = new Aetherion;
    cout << gemkinPtr->getName() << " encounters the legendary " << aetherionPtr->getName() << "!" << endl;

    // Display initial stats
    cout << gemkinPtr->getName() << "'s health: " << gemkinPtr->getHealth() << endl;
    cout << gemkinPtr->getName() << "'s level: " << gemkinPtr->getLevel() << endl;

    cout << aetherionPtr->getName() << "'s health: " << aetherionPtr->getHealth() << endl;

    // Determine who goes first based on speed (highest speed goes first)
    bool playerTurn = gemkinPtr->getSpeed() >= aetherionPtr->getSpeed();

    while (gemkinPtr->getHealth() > 0 && aetherionPtr->getHealth() > 0) {
        if (playerTurn) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << gemkinPtr->getName() << "'s turn!" << endl;
            cout << gemkinPtr->getName() << "'s health: " << gemkinPtr->getHealth() << endl;
            cout << gemkinPtr->getName() << "'s stamina: " << gemkinPtr->getStamina() << endl;
            gemkinPtr->displayMoves();

            int choice;
            cin >> choice;

            // Validate move selection
            while (choice < 1 || choice > 4) {
                cout << "Not a valid option. Please try again." << endl;
                cin >> choice;
            }

            // Execute chosen move
            switch (choice) {
                case 1:
                    if (gemkinPtr->getStamina() >= 10) {
                        gemkinPtr->usePhysicalMove(aetherionPtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 10);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 2:
                    if (gemkinPtr->getStamina() >= 20) {
                        gemkinPtr->useElementalMove(aetherionPtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 20);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 3:
                    if (gemkinPtr->getStamina() >= 40) {
                        gemkinPtr->useBurstMove(aetherionPtr);
                        gemkinPtr->setStamina(gemkinPtr->getStamina() - 40);
                    } else {
                        cout << "Not enough stamina! You missed your attack." << endl;
                    }
                    break;
                case 4:
                    gemkinPtr->useSupportMove();
                    break;
            }

            cout << "Aetherion health: " << max(aetherionPtr->getHealth(), 0) << endl;
            cout << "Aetherion stamina: " << max(aetherionPtr->getStamina(), 0) << endl;

        } else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Aetherion's turn!" << endl;

            int aetherionMove = rand() % 3;
            switch (aetherionMove) {
                case 0:
                    if (aetherionPtr->getStamina() >= 10) {
                        aetherionPtr->usePhysicalMove(gemkinPtr);
                        aetherionPtr->setStamina(aetherionPtr->getStamina() - 10);
                    } else {
                        cout << "Aetherion is charging up for the next attack..." << endl;
                    }
                    break;
                case 1:
                    if (aetherionPtr->getStamina() >= 20) {
                        aetherionPtr->useElementalMove(gemkinPtr);
                        aetherionPtr->setStamina(aetherionPtr->getStamina() - 20);
                    } else {
                        cout << "Aetherion is charging up for the next attack..." << endl;
                    }
                    break;
                case 2:
                    if (aetherionPtr->getStamina() >= 40) {
                        aetherionPtr->useBurstMove(gemkinPtr);
                        aetherionPtr->setStamina(aetherionPtr->getStamina() - 40);
                    } else {
                        cout << "Aetherion is charging up for the next attack..." << endl;
                    }
                    break;
            }
        }

        // Stamina regeneration for both fighters, without exceeding max stamina
        gemkinPtr->setStamina(min(gemkinPtr->getStamina() + 5, gemkinPtr->getMaxStamina()));
        aetherionPtr->setStamina(min(aetherionPtr->getStamina() + 5, aetherionPtr->getMaxStamina()));

        // Check for battle outcome, if player loses, plays dialogue, then your HP and Stamina are set to 20
        if (gemkinPtr->getHealth() <= 0) {
            cout << "Oh no! " << gemkinPtr->getName() << " has been defeated!" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << R"(
            You have spirit, but you are too weak. A pity... I expected more. 
            Return to me when your resolve and power are truly unshakable. 
            Only then will you be worthy of my true might.
            )" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "A voice commands you to get up... Destiny prevents " << gemkinPtr->getName() << "'s death. " << gemkinPtr->getName() << " has been revived with low health and stamina." << endl;
            gemkinPtr->setHealth(20);
            gemkinPtr->setStamina(20);
            cout << "TIP: You should head to the Healing Center to recover health and stamina." << endl;
            
            break;
        // If the boss dies, then dialogue and ending dialogue gets played. The game ends there.
        } else if (aetherionPtr->getHealth() <= 0) {
            bossDefeatedDialogue();
            theEnd();
            break;
        }

        playerTurn = !playerTurn;
    }

    delete aetherionPtr;
}

// Saves the game | OPTION 4
void saveGame() {
    string activeSaveFile;
    cout << "Do you already have a save file? [yes] or [no]" << endl;
    cin >> activeSaveFile;
    
    while ((activeSaveFile != "yes") && (activeSaveFile != "no")) {
        cout << "Please enter a valid response." << endl;
        cin >> activeSaveFile;
    }

    // If you already have a save file, input the name and it replaced your old information. Sets your health and stamina to MAX to ensure the correct value is saved
    if (activeSaveFile == "yes" ) {
        gemkinPtr->setHealth(gemkinPtr->getMaxHealth());
        gemkinPtr->setStamina(gemkinPtr->getMaxStamina());
        string filename;
        cout << "Please enter your save file name: " << endl;
        cin.ignore();
        getline(cin, filename);
        gemkinPtr->saveToFile(filename);
    }
    // If you don't have a save file, it tells you to select a name for it
    else if (activeSaveFile == "no" ) {
        gemkinPtr->setHealth(gemkinPtr->getMaxHealth());
        gemkinPtr->setStamina(gemkinPtr->getMaxStamina());
        string filename;
        cout << "What would you like to name your save file?: " << endl;
        cin.ignore();
        getline(cin, filename);
        gemkinPtr->saveToFile(filename);
    }
}

// This is where the game loops through the 4 options
void executePlayerPrompts() {

    playerPrompts(); // Plays the prompt listing the 4 choosable options
    int choice = 0;
    cin >> choice;
    cin.ignore();

    while (choice < 1 || choice > 4) {
      cout << "Not a valid option. Please try again." << endl;
      cin >> choice;
   }

    while (choice >= 1 && choice <= 4) {  
        switch(choice) 
        {
        case 1:
            cout << "Entering the wilderness..." << endl;
            wildernessPic();
            enterCombat();
            break;    
        case 2:             
            healingCenter();
            break;
   
        case 3:
        {
            cout << "WARNING! YOU MUST FINISH THE BOSS FIGHT. SAVING MID FIGHT IS NOT POSSIBLE" << endl;
            cout << "Are you sure you want to challenge the boss? Enter [yes] or [no]." << endl;
            cout << endl;
            cout << "TIP: Head to the Healing Center before you fight the boss." << endl;
            string challengeBoss;
            cin >> challengeBoss;
                
            while ((challengeBoss != "yes") && (challengeBoss != "no")) {
                cout << "Please enter a valid response." << endl;
                cin >> challengeBoss;
            }
            if (challengeBoss == "yes") {
                bossBattle();
            } 
            else if (challengeBoss == "no") {
                executePlayerPrompts();
            }
            break;
        }

        case 4:           
            saveGame();
            exit(0);  
        }
        // Prompts the user again and gives them options
        playerPrompts();
        cin >> choice;
        cin.ignore();

        // Ensures the user enters a valid option, if not, it will repeat the prompt
        if (choice < 1 || choice > 4) {
            cout << "Not a valid option. Please try again." << endl;
            cin >> choice;

            playerPrompts();
            cin >> choice;
            cin.ignore();
        }
    }
}


// Loads a valid save file
void loadSave() { 
    string activeSaveFile;
    cout << "Do you have a save file you would like to load? Enter [yes] or [no]" << endl;
    cin >> activeSaveFile;
    
    while ((activeSaveFile != "yes") && (activeSaveFile != "no")) {
        cout << "Please enter a valid response." << endl;
        cin >> activeSaveFile;
    }
    if (activeSaveFile == "yes") {
        string filename;
        cout << "Please enter your save file name: " << endl;
        cin.ignore();
        getline(cin, filename);

        ifstream input(filename);
        // This part is getting the name of the Gemkin from the save file, then using that to create the correct Gemkinptr
        if (input.is_open()) {
            string temp;
            if (getline(input, temp)) {
                if (temp.size() >= 6) {
                    string name = temp.substr(6); // Starts at substr(6) cuz file starts from Name: _____

                    // Determine which Gemkin to create for the ptr... otherwise code breaks :'(
                    if (name == "Igneel") {
                        gemkinPtr = new Igneel();
                    } else if (name == "Cryonox") {
                        gemkinPtr = new Cryonox();
                    } else if (name == "Sylvora") {
                        gemkinPtr = new Sylvora();
                    } else {
                        cout << "There is no Gemkin in save file. Exiting game..." << endl;
                        input.close();
                        exit(1);
                    }
                    input.close();

                    gemkinPtr->loadSaveFile(filename);
                    executePlayerPrompts();
                } else {
                    cout << "Invalid save file format. Exiting game..." << endl;
                    input.close();
                    exit(1);
                }
            } else {
                cout << "Save file is empty. Exiting game..." << endl;
                input.close();
                exit(1);
            }
        } else {
            cout << "File name was not found. Exiting game..." << endl;
            exit(1);
        }
    } else if (activeSaveFile == "no") {
        lore(); // This is optional
        introduceStarters(); // Introduces starter Gemkins, select only 1 starter
        executePlayerPrompts(); // Bulk of the game
    }
}

int main() {
    srand(time(0)); // For random numbers
    
    cout << "Welcome to Gemkins!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Before you begin, it is recommended to position the console so that it covers at least half of your screen for the best experience." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    loadSave();

    // Make sure there are no leaks
    delete gemkinPtr;
    return 0;
}