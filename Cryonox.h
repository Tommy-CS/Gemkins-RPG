#pragma once

#include <iostream>
#include <string>
#include "PlayableGemkin.h"

using namespace std;

class Cryonox : public PlayableGemkin {
    public:
        Cryonox(); // Cryonox's default constructor

        // These are the exclusive moves for Cryonox's combat
        void usePhysicalMove(Gemkin* opponent) override;
        void useElementalMove(Gemkin* opponent) override;
        void useBurstMove(Gemkin* opponent) override;
        void useSupportMove() override;

        void introduceGemkin() override;    // Introduces Cryonox
        virtual void displayMoves() override; // Displays Cryonox's moves, stamina costs, and move description

        ~Cryonox(); // Cryonox's destructor
    private:
        // Descriptions for all the moves
        string physicalMoveDesc;
        string elementalMoveDesc;
        string burstMoveDesc;
        string supportMoveDesc;

};