#ifndef Predator_H
#define Predator_H

#include <iostream>
#include <string>

#include "PredatorState.h"
#include "PredatorMemento.h"
#include "Prey.h"

using namespace std;

class Predator {
public:
    //constructor and destructor
	Predator(int healthPoints, string huntingMethod, int damage, string specialityAttack);
    ~Predator();

    //methods
    int getHP() const;
    void setHP(int health);
    string getHuntingMethod() const;
    void setHuntingMethod(string method);
    int getDamage() const;
    void setDamage(int d);
    string getSpeciality() const;
    void setSpeciality(string s);

    //template method
    void hunt(Prey* p);

    //primitive operations
    virtual bool catchPrey(Prey* p) = 0;
    virtual bool getAttacked(Prey* p) = 0;
    virtual bool attack(Prey* p) = 0;
    virtual void die() = 0;
    virtual void speciality() = 0;

    //used to get the type of predator when summarising the simulation results
    virtual string getType() = 0;

    //memento pattern
    void setMemento(PredatorMemento* m);
    PredatorMemento* createMemento();

protected:
    int healthPoints;
    string huntingMethod;
    int damage;
    string specialityAttack;

    //memento pattern
    PredatorState* state;
};

#endif