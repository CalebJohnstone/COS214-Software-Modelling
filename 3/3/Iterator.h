#ifndef Iterator_H
#define Iterator_H

#include "LinearStructure.h"

template<class T>
class LinearStructure;//

template<class T>
class Iterator {
	public:
		Iterator(){}
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool hasNext() = 0;
        virtual int current() = 0;	
};

#endif