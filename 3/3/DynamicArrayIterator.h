#ifndef DynamicArrayIterator_H
#define DynamicArrayIterator_H

#include "Iterator.h"

template<class T>
class DynamicArray;

template<class T>
class DynamicArrayIterator : public Iterator<T> {
	public:
		DynamicArrayIterator(DynamicArray<T>* array){
            this->array = array->clone();
            currentIndex = 0;
        }

        ~DynamicArrayIterator(){
            delete[] array;
            array = nullptr;
        }

        void first(){
           currentIndex = 0;
        }

        void next(){
            ++currentIndex;
        }

        bool hasNext(){
            return (currentIndex <= array->numElements-1);
        }

        T current(){
            return array->get(currentIndex);
        }

        int getCurrentIndex(){
            return currentIndex;
        }

	private:
        DynamicArray<T>* array;
        int currentIndex;
	
};

#endif