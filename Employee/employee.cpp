#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

employee::employee(string n, int i, double s){
    setName(n);
    setid(i);
    setsalary(s);
}

employee::employee(){
    setName("Unkown");
    setid(115566);
    setsalary(1200);
}

// ----------- Setter
void employee::setName(string n){
    name = n;
}
void employee::setid(int i){
    bool status = true;
    for(int j=i;j > 0; j /= 10){
        if(j % 10 == 5 || j % 10 == 6 || j % 10 == 1){
            status = true;
            continue;
        }else {
            status = false;
            break;
        }
    }
    if(status == true){
        id = i;
    }else {
        cout << "Invalid ID";
    }
}
void employee::setsalary(double s){
    if(s > 1500){
        salary = s;
    }else {
        salary = 1500;
        cout << "Salary adjusted to minimum (1500)";
    }
}

// ----------- Getter
string employee::getName(){ return name; }
int employee::getid(){ return id;}
double employee::getsalary(){ return salary; }

// --------- Destructor ----------
employee::~employee(){
    cout << "Employee has been removed from memory";
}
