#ifndef CheetahFactory_H
#define CheetahFactory_H

#include "PredatorFactory.h"
#include "Cheetah.h"

class CheetahFactory : public PredatorFactory {
public:
    CheetahFactory();
    ~CheetahFactory();

    Predator* createPredator(string huntingMethod, string speciality);
};

#endif