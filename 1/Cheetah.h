#ifndef Cheetah_H
#define Cheetah_H

#include "Predator.h"

using namespace std;

class Cheetah : public Predator {
public:
    //constructor
    Cheetah(int healthPoints, string huntingMethod, int damage, string specialityAttack);
    Cheetah(string huntingMethod, string specialityAttack);
    ~Cheetah();
    
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