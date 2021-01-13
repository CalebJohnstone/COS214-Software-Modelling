#ifndef Lion_H
#define Lion_H

#include "Predator.h"

using namespace std;

class Lion : public Predator {
public:
    //constructor
    Lion(int healthPoints, string huntingMethod, int damage, string specialityAttack);
    Lion(string huntingMethod, string specialityAttack);
    ~Lion();

    //primitive operations
    bool catchPrey(Prey* p);
    bool getAttacked(Prey* p);
    bool attack(Prey* p);
    void die();
    void speciality();

    string getType();

private:

};

#endif