#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
using namespace std;

void Department::print() {
    cout << "Department Details: " << endl;
    cout << " - ID: " << departID << endl;
    cout << " - Name: " << departName << endl;
    cout << "--------------------------" << endl;
}

StaffMember::StaffMember(int id, string n, string ph, string eml) {
    employeeID = id;
    name = n;
    phone = ph;
    email = eml;
}

string StaffMember::Print() {
    string data = "ID: " + to_string(employeeID) + " | Name: " + name + " | Phone: " + phone + " | Email: " + email;
    return data; 
}

Volunteer::Volunteer(int id, string n, string ph, string eml, double amt) 
    : StaffMember(id, n, ph, eml) { 
    amount = amt; 
}

double Volunteer::Pay() {
    return amount; 
}

string Volunteer::Print() {
    return StaffMember::Print() + " | Type: Volunteer | Amount: " + to_string(amount);
}

Employee::Employee(int id, string n, string ph, string eml, string ssn)
    : StaffMember(id, n, ph, eml) {
    socialSecurityNumber = ssn;
}

string Employee::Print() {
    return StaffMember::Print() + " | SSN: " + socialSecurityNumber;
}

double Employee::Pay() {
    return 0.0;
}

HourlyEmployee::HourlyEmployee(int id, string n, string ph, string eml, string ssn, double r)
    : Employee(id, n, ph, eml, ssn) {
    rate = r;
    hoursWorked = 0;
}

void HourlyEmployee::addHours(int moreHours) {
    hoursWorked += moreHours;
}

double HourlyEmployee::Pay() {
    return hoursWorked * rate;
}

string HourlyEmployee::Print() {
    return Employee::Print() + " | Rate: " + to_string(rate) + " | Hours Worked: " + to_string(hoursWorked);
}

SalariedEmployee::SalariedEmployee(int id, string n, string ph, string eml, string ssn, double sal)
    : Employee(id, n, ph, eml, ssn) {
    salary = sal;
}

double SalariedEmployee::Pay() {
    return salary;
}

string SalariedEmployee::Print() {
    return Employee::Print() + " | Salary: " + to_string(salary);
}

ExecutiveEmployee::ExecutiveEmployee(int id, string n, string ph, string eml, string ssn, double sal, double b)
    : SalariedEmployee(id, n, ph, eml, ssn, sal) {
    bonus = b;
}

void ExecutiveEmployee::addBonus(double moreBonus) {
    bonus += moreBonus;
}

double ExecutiveEmployee::Pay() {
    return SalariedEmployee::Pay() + bonus;
}

string ExecutiveEmployee::Print() {
    return SalariedEmployee::Print() + " | Bonus: " + to_string(bonus);
}

CommissionEmployee::CommissionEmployee(int id, string n, string ph, string eml, string ssn, double t)
    : Employee(id, n, ph, eml, ssn) {
    target = t;
}

double CommissionEmployee::Pay() {
    return target * 0.05;
}

string CommissionEmployee::Print() {
    return Employee::Print() + " | Target: " + to_string(target) + " | Commission (5%): " + to_string(Pay());
}

void Budget::increaseBudget(double amount) {
    value += amount;
}


Project::Project(int id, string loc, Employee* m) {
    projectID = id;
    location = loc;
    manager = m;
    currentCost = 0; 
}

void Project::addBudget(Budget b) {
    budgetList.push_back(b); 
}

double Project::getTotalBudget() {
    double total = 0;
    for (int i = 0; i < budgetList.size(); i++) {
        total += budgetList[i].getValue();
    }
    return total;
}

void Project::print() {
    cout << "Project ID: " << projectID << " | Location: " << location << endl;
    cout << "Total Project Budget: " << getTotalBudget() << endl;
    // بنطبع بيانات المدير لو موجود
    if (manager != nullptr) {
        cout << "Managed by: " << manager->Print() << endl;
    }
    cout << "-----------------------------------" << endl;
}

Staff::~Staff() {
    for (int i = 0; i < staffList.size(); i++) {
        delete staffList[i];
    }
    staffList.clear();
}

void Staff::addMember(StaffMember* m) {
    staffList.push_back(m);
}

void Staff::delMember(int id) {
    for (int i = 0; i < staffList.size(); i++) {
        if ((*staffList[i]).getID() == id) {
            delete staffList[i];
            staffList.erase(staffList.begin() + i);
            return;
        }
    }
}

void Staff::showAll() {
    for (int i = 0; i < staffList.size(); i++) {
        cout << (*staffList[i]).Print() << endl;
    }
}

double Staff::calcPayroll() {
    double total = 0;
    for (int i = 0; i < staffList.size(); i++) {
        total += (*staffList[i]).Pay();
    }
    return total;
}
