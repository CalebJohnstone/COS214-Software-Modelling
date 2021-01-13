#include "SocialSiteUser.h"

SocialSiteUser::SocialSiteUser(SocialSiteMediator* mediator, string name) : User(mediator, name), status("I am using SocialSite"){
    myInbox = new Inbox(50);
    old = new OldStatus(10);

    old->save(status);
}

void SocialSiteUser::changeStatus(string newStatus){
    status = newStatus;

    //tell other users
    mediator->notify(this, username + " has changed her status to: " + status);
}

string SocialSiteUser::viewStatus(){
    return status;
}

void SocialSiteUser::receiveMessage(string message){
    cout << username << " received: " << message << endl;
    saveMessage(message);
}

void SocialSiteUser::postMessage(string message){
    mediator->notify(this, username + " sent: " + message);
}

void SocialSiteUser::saveMessage(string message){
    //save the message to the inbox
    myInbox->save(message);
}

void SocialSiteUser::viewInbox(){
    //print all of the messages in the inbox
    if(myInbox->getNumMessages() == 0){
        cout << "Inbox Empty" << endl;
    }else{
        for(int i = 0; i < myInbox->getNumMessages(); ++i){
            cout << myInbox->load(i) << endl;
        }  
    }
}

void SocialSiteUser::saveStatus(){
    old->save(status);
}

void SocialSiteUser::loadStatus(){
    //set the status to the last status added to the oldStatus array
    if(old->getNumStatus() == 0){
        cout << "You do not have any old status to use" << endl;
    }else if(old->getNumStatus() == 1){
        cout << "You only have 1 old status. Setting your status to that now." << endl;
    }else{
        int statusNumber;
        cout << "Choose status [0 - " << old->getNumStatus()-1 << "]" << endl;
        cin >> statusNumber;

        if(statusNumber < 0 || statusNumber >= old->getNumStatus()){
            cout << "Invalid option" << endl;
        }else{
            this->changeStatus(old->load(statusNumber));
        }
    }
}