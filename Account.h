#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
    private: 
        string StudentName;
        double GPA ;

    public:
        void setName(string n);
        void setGPA(double g);

        string getName();
        double getGPA();
};

#endif
