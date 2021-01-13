#include "DynamicArray.h"

void print(DynamicArray<int>* array){
    //iterate through the elements and print them
    cout << "printing the array contents" << endl;

    DynamicArrayIterator<int>* it = new DynamicArrayIterator<int>(array);

    for(it->first(); it->hasNext(); it->next()){
        cout << "array[" << it->getCurrentIndex() << "] = " << it->current() << endl;
    }

    cout << endl;
}

int main(){
    DynamicArray<int>* array = new DynamicArray<int>(10);

    //insert elements
    cout << "inserting even numbers" << endl;

    for(int i = 0; i < 10; ++i){
        array->insert(i, i*2);
    }

    print(array);

    //remove elements
    cout << "removing elements that are a multiple of 6:" << endl;

    for(int i = 0; ; i += 2){
        try{
            cout << array->remove(i) << endl;
        }catch(char const* c){
            break;
        }
    }

    cout << endl;

    print(array);

    //clear the array
    cout << "clearing the array" << endl;
    cout << endl;
    array->clear();

    //insert multiples of 3
    cout << "inserting multiples of 3" << endl;

    for(int i = 0; i < 10; ++i){
        array->insert(i, i*3);
    }

    print(array);

    delete array;
    array = nullptr;

    return 0;
}