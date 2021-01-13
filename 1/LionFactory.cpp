#include "LionFactory.h"

LionFactory::LionFactory(){}

LionFactory::~LionFactory(){}

Predator* LionFactory::createPredator(string huntingMethod, string speciality){
    return new Lion(huntingMethod, speciality);
}