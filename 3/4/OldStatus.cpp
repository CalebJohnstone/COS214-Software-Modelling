#include "OldStatus.h"

OldStatus::OldStatus(int _MaxStatus){
    MaxStatus = _MaxStatus;
    numStatus = 0;

    status = new string[MaxStatus];
}

OldStatus::~OldStatus(){
    delete[] status;
    status = nullptr;
}

void OldStatus::save(string _status){
    //save the given status (FIFO queue)
    if(numStatus < MaxStatus){
        //array is not full --> add to the end
        status[numStatus++] = _status;
    }else{
        //array is full so shift left
        for(int i = 0; i < MaxStatus-1; ++i){
            //bring down
            status[i] = status[i+1];
        }

        //place in the last position in the array
        status[MaxStatus-1] = _status;
    }
}

string OldStatus::load(int index){
    if(index < 0){
        return "Invalid index: index is negative";
    }else if(index >= MaxStatus){
        return "Invalid index: index is at least the maximum number of status";
    }
    else{
        return status[index];
    }
}

int OldStatus::getNumStatus(){
    return numStatus;
}