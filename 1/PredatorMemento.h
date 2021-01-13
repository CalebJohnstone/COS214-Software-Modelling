#ifndef PredatorMemento_H
#define PredatorMemento_H

#include "PredatorState.h"

using namespace std;

class PredatorMemento {
public:
    PredatorMemento(int HP, string huntingMethod, int damage, string specialityAttack);
    ~PredatorMemento();

    PredatorState* getState() const;

private:
    friend class Predator;

    PredatorState* state;
};

#endif