#pragma once

#include <iostream>
#include <string>
#include "PlayableGemkin.h"

using namespace std;

class Sylvora : public PlayableGemkin {
    public:
        Sylvora(); // Sylvora's default constructor

        // These are the exclusive moves for Sylvora's combat
        void usePhysicalMove(Gemkin* opponent) override;
        void useElementalMove(Gemkin* opponent) override;
        void useBurstMove(Gemkin* opponent) override;
        void useSupportMove() override;

        void introduceGemkin() override;    // Introduces Sylvora
        virtual void displayMoves() override;   // Displays Sylvora's moves, stamina costs, and move description

 
        ~Sylvora(); // Sylvora's destructor
    private:
        // Descriptions for all the moves
        string physicalMoveDesc;
        string elementalMoveDesc;
        string burstMoveDesc;
        string supportMoveDesc;

};