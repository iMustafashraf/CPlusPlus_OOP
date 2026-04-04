#include <iostream>
#include <string>
using namespace std;

class employee {
    private: 
        string name;
        int id;
        double salary;
    public:
        employee();
        employee(string n, int i, double s);
        ~employee();
    // setters
        void setName(string n);
        void setid(int i);
        void setsalary(double s);
    // Getter
        string getName();
        int getid();
        double getsalary();
};
