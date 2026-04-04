#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

void Account::setName(string n){
    StudentName = n;
}

void Account::setGPA(double g){
    if(g >= 0 && g <= 4){
        GPA = g;
    }else {
        GPA = 0;
        cout << "please, enter the right GPA";
    }
}

double Account::getGPA(){
    return GPA;
}

string Account::getName(){
    return StudentName;
}

int main (){
    Account Mohamed1;
    Mohamed1.setName("Mohamed Ghaly");
    Mohamed1.setGPA(3.8);

    cout << Mohamed1.getName() << " has Gpa = " << Mohamed1.getGPA();
    return 0;
}
