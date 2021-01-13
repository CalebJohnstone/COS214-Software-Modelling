#ifndef PreyMemento_H
#define PreyMemento_H

#include "PreyState.h"

using namespace std;

class PreyMemento {
public:
    PreyMemento(int HP, string type, int damage);
    ~PreyMemento();

    PreyState* getState() const;

private:
    friend class Prey;

    PreyState* state;
};

#endif