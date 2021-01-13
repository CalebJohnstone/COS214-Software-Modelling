#include "PreyStore.h"

PreyStore::PreyStore(int numberOfPrey){
    currentPrey = 0;
    preyCount = numberOfPrey;

    //intialisation for the mementos
    mementos = new PreyMemento*[preyCount];

    for(int i = 0; i < preyCount; i++){
        mementos[i] = nullptr;
    }
}

PreyStore::~PreyStore(){
    for(int i = 0; i < preyCount; i++){
        if(mementos[i]){
            delete mementos[i];
        }
    }

    delete[] mementos;
    mementos = nullptr;
}

PreyMemento* PreyStore::getMemento(int index) const{
    //get a specific memento at the provided index --> used when re-instating the Predator to its original state
    if(index >= 0 && index < preyCount){
        return mementos[index];
    }
    else{
        return nullptr;
    }    
}

void PreyStore::addMemento(PreyMemento* m){
    if(currentPrey <= preyCount-1){
        mementos[currentPrey++] = m;
    }
    else{
        cout << "PreyStore is full. You cannot add another PreyMemento." << endl;
    }    
}

int PreyStore::getTotalPreyCount() const{
    return preyCount;
}