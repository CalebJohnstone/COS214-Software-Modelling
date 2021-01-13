#ifndef PreyStore_H
#define PreyStore_H

#include "PreyMemento.h"

using namespace std;

class PreyStore {
public:
    PreyStore(int numberOfPrey);
    ~PreyStore();

    PreyMemento* getMemento(int index) const;
    void addMemento(PreyMemento* m);
    int getTotalPreyCount() const;
private:
    int preyCount;
    int currentPrey;
    PreyMemento** mementos;
};

#endif