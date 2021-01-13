#ifndef SocialSiteUser_H
#define SocialSiteUser_H

#include "User.h"
#include "Inbox.h"
#include "OldStatus.h"

class SocialSiteUser : public User {
	public:
		SocialSiteUser(SocialSiteMediator* mediator, string name);
        void changeStatus(string newStatus);
        string viewStatus();
        virtual void receiveMessage(string message);
        void postMessage(string message);
        void saveMessage(string message);
        void viewInbox();
        void saveStatus();
        void loadStatus();
    
    protected:
        string status;
        Inbox* myInbox;
        OldStatus* old;

};

#endif