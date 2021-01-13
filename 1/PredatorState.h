#ifndef PredatorState_H
#define PredatorState_H

#include <string>
#include <iostream>

using namespace std;

class PredatorState {
public:
    PredatorState(int HP, string huntingMethod, int damage, string specialityAttack);
    ~PredatorState();
    
    int getHP() const;
    string getHuntingMethod() const;
    int getDamage() const;
    string getSpeciality() const;

private:
    int healthPoints;
    string huntingMethod;
    int damage;
    string specialityAttack;
};

#endif