#ifndef PredatorStore_H
#define PredatorStore_H

#include "PredatorMemento.h"

using namespace std;

class PredatorStore {
public:
    PredatorStore(int numberOfPredator);
    ~PredatorStore();

    PredatorMemento* getMemento(int index) const;
    void addMemento(PredatorMemento* m);
    int getTotalPredatorCount() const;
private:
    int predatorCount;
    int currentPredator;
    PredatorMemento** mementos;
};

#endif