#ifndef PredatorFactory_H
#define PredatorFactory_H

#include "Predator.h"

class PredatorFactory {
public:
    PredatorFactory(){}
    virtual ~PredatorFactory(){}

    //implemented in the subclasses
    virtual Predator* createPredator(string, string) = 0;
};

#endif