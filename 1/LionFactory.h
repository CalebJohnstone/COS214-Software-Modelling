#ifndef LionFactory_H
#define LionFactory_H

#include "PredatorFactory.h"
#include "Lion.h"

class LionFactory : public PredatorFactory {
public:
    LionFactory();
    ~LionFactory();

    Predator* createPredator(string huntingMethod, string speciality);
};

#endif