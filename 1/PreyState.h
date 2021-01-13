#ifndef PreyState_H
#define PreyState_H

#include <string>
#include <iostream>

using namespace std;

class PreyState {
public:
    PreyState(int HP, string type, int damage);
    ~PreyState();
    
    int getHP() const;
    string getType() const;
    int getDamage() const;

private:
    int HP;
    string type;
    int damage;
};

#endif