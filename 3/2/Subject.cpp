#include "Subject.h"

Subject::Subject(){

}

void Subject::attach(Observer* observer){
    mObservers.push_back(observer);
}

void Subject::notify(){
    for(vector<Observer*>::iterator it = mObservers.begin(); it != mObservers.end(); ++it){
        (*it)->update();
    }
}