#ifndef OldStatus_H
#define OldStatus_H

#include <iostream>
#include <string>

using namespace std;

class OldStatus {
	public:
		OldStatus(int _MaxStatus);
        ~OldStatus();
        void save(string status);
        string load(int index);
        int getNumStatus();

    private:
        int numStatus;
        int MaxStatus;
        string* status;
};

#endif