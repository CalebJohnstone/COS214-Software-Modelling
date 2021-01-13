#include "CheetahFactory.h"

CheetahFactory::CheetahFactory(){}

CheetahFactory::~CheetahFactory(){}

Predator* CheetahFactory::createPredator(string huntingMethod, string speciality){
    return new Cheetah(huntingMethod, speciality);
}