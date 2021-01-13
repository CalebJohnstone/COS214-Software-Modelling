#if !defined(Prey_H)
#define Prey_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "PreyState.h"
#include "PreyMemento.h"

using namespace std;
class Prey
{
private:
    int HP;
    string type;
    int damage;

    //memento pattern
    PreyState* state;
public:
    Prey();
    Prey(int HP, string type, int damage);
    ~Prey();
    Prey *clone();
    int getHP();
    void setHP(int HP);
    string getType();
    void setType(string type);
    int getDamage();
    void setDamage(int damage);
    bool run();
    int fight();
    int takeDamage(int damage);

    //memento pattern
    void setMemento(PreyMemento* m);
    PreyMemento* createMemento();
};

#endif // Prey_H