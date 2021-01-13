#include "PredatorStore.h"

PredatorStore::PredatorStore(int numberOfPredator){
    currentPredator = 0;
    predatorCount = numberOfPredator;
    mementos = new PredatorMemento*[predatorCount];

    for(int i = 0; i < predatorCount; i++){
        mementos[i] = nullptr;
    }
}

PredatorStore::~PredatorStore(){
    for(int i = 0; i < predatorCount; i++){
        if(mementos[i]){
            delete mementos[i];
        }
    }

    delete[] mementos;
    mementos = nullptr;
}

PredatorMemento* PredatorStore::getMemento(int index) const{
    //get the specified PredatorMemento
    if(index >= 0 && index < predatorCount){
        return mementos[index];
    }
    else{
        return nullptr;
    }    
}

void PredatorStore::addMemento(PredatorMemento* m){
    if(currentPredator <= predatorCount-1){
        mementos[currentPredator++] = m;
    }
    else{
        cout << "PredatorStore is full. You cannot add another PredatorMemento." << endl;
    }    
}

int PredatorStore::getTotalPredatorCount() const{
    return predatorCount;
}