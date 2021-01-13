#include "ConcreteSocialSiteMediator.h"

ConcreteSocialSiteMediator::ConcreteSocialSiteMediator(){
    //intialise the users array
    users = new User*[10];//what would be the max num of users ???
    numUsers = 0;
}

ConcreteSocialSiteMediator::~ConcreteSocialSiteMediator(){
    for(int i = 0; i < numUsers; ++i){
        delete users[i];
    }

    delete[] users;
    users = nullptr;
}

void ConcreteSocialSiteMediator::notify(User* username, string message){
    for(int i = 0; i < numUsers; ++i){
        if(users[i] != username){
            //send message to other user
            users[i]->receiveMessage(message);
        }
    }
}

bool ConcreteSocialSiteMediator::addUser(string username){
    //check if the user is already in the array
    for(int i = 0; i < numUsers; ++i){
        if(users[i]->getName() == username){
            return false;
        }
    }

    if(numUsers == 10){
        return false;//max number of users reached
    }

    //add the user
    users[numUsers++] = new SocialSiteUser(this, username);
    return true;
}

User* ConcreteSocialSiteMediator::getUser(string name){
    for(int i = 0; i < numUsers; ++i){
        if(users[i]->getName() == name){
            return users[i];
        }
    }

    return NULL;
}