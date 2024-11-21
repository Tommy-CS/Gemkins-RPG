#pragma once
#include "Gemkin.h"

class PlayableGemkin : public Gemkin {
public:
    PlayableGemkin(string _name, string _mysticCore, int _level, int _health, int _stamina, int _baseAttackPower, int _defensePower, int _speed);

    int getExperience();
    string getSupportMove();

    void setSupportMove(string newSupportMove);

    void gainExperience(int newExperience);
    void loseExperience(int newExperience);
    void saveToFile(string filename);
    void loadSaveFile(string filename);

    //might need to change the pointer type...
    virtual void usePhysicalMove(Gemkin* opponent) override;
    virtual void useElementalMove(Gemkin* opponent) override;
    virtual void useBurstMove(Gemkin* opponent) override;
    virtual void useSupportMove();
    virtual void displayMoves();
    virtual void introduceGemkin();

    ~PlayableGemkin();

private:
    int experience;
    string supportMove;
};
