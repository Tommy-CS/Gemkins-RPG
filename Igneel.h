#pragma once

#include <iostream>
#include <string>
#include "PlayableGemkin.h"

using namespace std;

class Igneel : public PlayableGemkin {
    public:
        Igneel();   // Default constructor for Igneel

        // These are the exclusive moves for Igneel's combat
        void usePhysicalMove(Gemkin* opponent) override;
        void useElementalMove(Gemkin* opponent) override;
        void useBurstMove(Gemkin* opponent) override;
        void useSupportMove() override;
  
        void introduceGemkin() override;    // Introduces Igneel 
        virtual void displayMoves() override;   // Displays Igneel's moves, stamina costs, and move description

        ~Igneel(); // Igneel's destructor
    private:
        // Descriptions for all the moves
        string physicalMoveDesc;
        string elementalMoveDesc;
        string burstMoveDesc;
        string supportMoveDesc;

};