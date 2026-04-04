#include <iostream>
#include "employee.h" 

int main() {
    employee AhmedTamer;

    std::cout << "Employee name is : " << AhmedTamer.getName() << endl;
    std::cout << "Employee ID is   : " << AhmedTamer.getid() << endl;
    std::cout << "Employee Salary is: " << AhmedTamer.getsalary() << endl;

    AhmedTamer.setsalary(1000); 
    cout << "Salary after trying to set 1000: " << AhmedTamer.getsalary() << endl;

    AhmedTamer.setid(112566);
        cout << "ID after trying to set num not 1,5,6: " << AhmedTamer.getid() << endl;

    AhmedTamer.setName("Iam not Ahmed Tamer.. hehehe");
        cout << "Ahmed Tamer say that his name is : " << AhmedTamer.getName();
    return 0;
}
