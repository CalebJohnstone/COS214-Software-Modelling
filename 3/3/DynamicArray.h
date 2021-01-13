#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "LinearStructure.h"
#include "DynamicArrayIterator.h"

#include <string>

template<class T>
class DynamicArray : public LinearStructure<T>
{
		public:
		
		DynamicArray(int s){
			if(s <= 0){
				throw "Invalid size provided";
				//throw error;
			}

			size = s;
			elements = new T*[size];

			for(int e = 0; e < size; e++){
				elements[e] = 0;
			}

			numElements = 0;
		}
		
		DynamicArray(const DynamicArray<T>& other){
			size=other.size;
			elements = new T*[size];
	
			for(int i=0;i<size;i++){
				elements[i] =other.elements[i];
			}

			numElements=other.numElements;
		}
		
		virtual DynamicArray<T>* clone(){
			DynamicArray<T> *other = new DynamicArray<T>(*this);
			return other;
		}
		
		virtual ~DynamicArray(){
			for(int i=0;i<size;i++)
				delete elements[i];
	
			delete [] elements;
			elements=0;
		}
		
		virtual void insert(int index, T element){
			int newIndex=index;
	
			if(index<0)
				return;
				
			if(index>=size){	
				resize(newIndex + 1);
			}
			if(elements[index]!=0){
				for(int y=size;y>=index;y--){
					resize(newIndex + 1);

					if(elements[y]){
						elements[y+1]= elements[y];
					}
					else{
						elements[y+1]= elements[y];
					}

					newIndex++;
				}
				elements[index] = new T(element);
			}
			else{
				elements[index] = new T(element);
			}

			numElements++;
		}
		
		virtual T remove(int index){
			T other;
	
			if(elements[index] == 0){
				throw "empty structure";
			}
			else{
				other=*(elements[index]);
				elements[index]=0;

				for(int i = index; i < size; i++){
					elements[i] = elements[i + 1];
				}

				elements[size - 1] = 0;
			}

			numElements--;
			return other;
		}
		
		virtual T get(int index) const{
			if(elements[index]==0){
				throw "empty structure";
			}
			else if(index < 0 || index > numElements){
				throw "invalid index";
			}

			return *(elements[index]);
		}
		
		virtual bool isEmpty(){
			return (numElements == 0);
		}		
		
		virtual void clear(){
			for(int s=0;s<size;s++){
				elements[s]=0;
			}

			numElements=0;
		}

		//createIterator
		Iterator<T>* createIterator(){
			return new DynamicArrayIterator<T>(this);
		}
		
	private:
		friend class DynamicArrayIterator<T>;
		
		void resize(int howMuch){
			T** Array = new T *[howMuch];
		
			for(int i = 0; i < howMuch; i++){
				Array[i] = 0;
			}
		
			if(howMuch < numElements){
				for(int i = 0; i < howMuch; i++){
					Array[i] = new T(*(elements[i]));
				}

				numElements = howMuch;
			}
			else{
				for(int i = 0; i < numElements; i++){
					Array[i] = new T(*(elements[i]));
				}
			}
		
			delete[] elements;
		
			elements = Array;
			size = howMuch;
		}
				
		T ** elements;
		
		int size;

		int numElements;
};

#endif