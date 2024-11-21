#pragma once

#include <iostream>
#include <string>
#include "Gemkin.h"

using namespace std;

// 
class Aetherion : public Gemkin {
    public:
        Aetherion(); // Aetherion's default constructor
        
        // These are the exclusive moves for Aetherion's combat
        void usePhysicalMove(Gemkin* opponent) override;
        void useElementalMove(Gemkin* opponent) override;
        void useBurstMove(Gemkin* opponent) override;

        ~Aetherion(); // Aetherion's destructor
    private:
        // Descriptions for all the moves (only has 3 b/c no healing move)
        string physicalMoveDesc;
        string elementalMoveDesc;
        string burstMoveDesc;

};
