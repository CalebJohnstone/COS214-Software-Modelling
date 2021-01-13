#include "Inbox.h"

Inbox::Inbox(int _MaxMessages){
    MaxMessages = _MaxMessages;
    numMessages = 0;

    messages = new string[MaxMessages];
}

Inbox::~Inbox(){
    delete[] messages;
    messages = nullptr;
}

void Inbox::save(string message){
    //save the given message (FIFO queue)
    if(numMessages < MaxMessages){
        //array is not full --> add to the end
        messages[numMessages++] = message;
    }else{
        //array is full so shift left
        for(int i = 0; i < MaxMessages-1; ++i){
            //bring down
            messages[i] = messages[i+1];
        }

        //place in the last position in the array
        messages[MaxMessages-1] = message;
    }
}

string Inbox::load(int index){
    if(index < 0){
        return "Invalid index: index is negative";
    }else if(index >= MaxMessages){
        return "Invalid index: index is at least the maximum number of messages";
    }
    else{
        return messages[index];
    }
}

int Inbox::getNumMessages(){
    return numMessages; 
}