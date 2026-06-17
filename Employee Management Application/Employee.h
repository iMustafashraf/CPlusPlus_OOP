#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Department {
private:
    int departID;
    string departName;
public:
    Department(int id, string name) : departID(id), departName(name) {}
    void print(); // يطبع تفاصيل القسم
};

class StaffMember {
protected: 
    int employeeID;
    string name;
    string phone; 
    string email;
public:
    StaffMember(int id, string n, string ph, string eml);
    virtual string Print(); 
    virtual double Pay() = 0;
    int getID() { return employeeID; }
    virtual ~StaffMember() {} 
};

// ------------------------------ The Hierachy -------------------------

class Volunteer : public StaffMember {
private:
    double amount; // في الرسمة مكتوب amount
public:
    Volunteer(int id, string n, string ph, string eml, double amt);
    string Print() override;
    double Pay() override; // هيرجع الـ amount كقيمة
};

class Employee : public StaffMember {
protected:
    string socialSecurityNumber;
public:
    Employee(int id, string n, string ph, string eml, string ssn);
    string Print() override;
    double Pay() override;
};


// ------------------------------------- Derived Employees ---------------------------

class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double rate;
public:
    HourlyEmployee(int id, string n, string ph, string eml, string ssn, double r);
    void addHours(int moreHours); 
    double Pay() override;   // rate * hours
    string Print() override;
};

class SalariedEmployee : public Employee {
protected: // خليتها protected عشان الـ Executive يشوف الـ salary
    double salary;
public:
    SalariedEmployee(int id, string n, string ph, string eml, string ssn, double sal);
    double Pay() override;   // salary
    string Print() override;
};

class ExecutiveEmployee : public SalariedEmployee {
private:
    double bonus;
public:
    ExecutiveEmployee(int id, string n, string ph, string eml, string ssn, double sal, double b);
    void addBonus(double moreBonus);
    double Pay() override;   // salary + bonus
    string Print() override;
};

class CommissionEmployee : public Employee {
private:
    double target;
public:
    CommissionEmployee(int id, string n, string ph, string eml, string ssn, double t);
    double Pay() override;   // 5% * target 
    string Print() override;
};

// ----------------------------------------- Staff, Project, Budget -----------------------------
class Budget {
private:
    int id;
    double value;
public:
    Budget(int bId, double val) : id(bId), value(val) {}
    void increaseBudget(double amount);
    double getValue() { return value; }
};

class Project {
private:
    int projectID;
    string location;
    Employee* manager; 
    double currentCost;
    vector<Budget> budgetList; 
public:
    Project(int id, string loc, Employee* m);
    void addBudget(Budget b);
    double getTotalBudget();
    void print();
};

class Staff {
private:
    vector<StaffMember*> staffList; 
public: 
    ~Staff(); 
    void addMember(StaffMember* m); 
    void delMember(int id); 

    void showAll();
    double calcPayroll();
};
