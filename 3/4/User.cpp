#include "User.h"

User::User(SocialSiteMediator* mediator, string name) : mediator(mediator), username(name){

}

void User::changed(string message){
    //TODO: use the message

    mediator->notify(this, message);
}

string User::getName(){
    return username;
}