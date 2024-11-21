#pragma once

#include <iostream>
#include <string>
#include "Gemkin.h"

using namespace std;

class Dreadcore : public Gemkin {
    public:
        Dreadcore(int originalLevel); // Dreadcore's default constructor

        // These are the exclusive moves for Dreadcore's combat
        void usePhysicalMove(Gemkin* opponent) override;
        void useElementalMove(Gemkin* opponent) override;
        void useBurstMove(Gemkin* opponent) override;

        ~Dreadcore(); // Dreadcore's destructor
    private:
        // Descriptions for all the moves (only has 3 b/c one of the moves siphons HP)
        string physicalMoveDesc;
        string elementalMoveDesc;
        string burstMoveDesc;

        int randHealth; // Generates a random amount of health
        int randStamina; // Generates a random amount of stamina

};