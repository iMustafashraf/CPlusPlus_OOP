#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 1. نجهز كائن الـ Staff (الـ HR بتاعنا)
    Staff hrManager;

    // 2. ننشئ 6 موظفين بأنواع مختلفة (Polymorphism)
    // لاحظ إننا بنستخدم new عشان نبعتهم للـ staffList كـ Pointers
    
    // متطوع (بياخد مكافأة 500 جنيه)
    StaffMember* m1 = new Volunteer(1, "Ahmed", "010", "ahmed@mail.com", 500.0);
    
    // موظف ساعة (بياخد 100 جنيه في الساعة واشتغل 10 ساعات)
    HourlyEmployee* m2 = new HourlyEmployee(2, "Mona", "011", "mona@mail.com", "SSN-22", 100.0);
    m2->addHours(10);
    
    // موظف بمرتب ثابت (3000 جنيه)
    StaffMember* m3 = new SalariedEmployee(3, "Samy", "012", "samy@mail.com", "SSN-33", 3000.0);
    
    // مدير (مرتب 5000 + بونص 1000)
    ExecutiveEmployee* m4 = new ExecutiveEmployee(4, "Zaki", "015", "zaki@mail.com", "SSN-44", 5000.0, 0.0);
    m4->addBonus(1000.0);
    
    // موظف عمولة (Target 20000 وعمولته 5%)
    StaffMember* m5 = new CommissionEmployee(5, "Laila", "019", "laila@mail.com", "SSN-55", 20000.0);
    
    // موظف ساعة تاني (سعر ساعته 50 واشتغل 20 ساعة)
    HourlyEmployee* m6 = new HourlyEmployee(6, "Omar", "017", "omar@mail.com", "SSN-66", 50.0);
    m6->addHours(20);

    // 3. نضيفهم كلهم للـ Staff
    hrManager.addMember(m1);
    hrManager.addMember(m2);
    hrManager.addMember(m3);
    hrManager.addMember(m4);
    hrManager.addMember(m5);
    hrManager.addMember(m6);

    // 4. نعرض بيانات كل الناس
    cout << "--- All Staff Members Data ---" << endl;
    hrManager.showAll();

    // 5. نحسب إجمالي الرواتب
    cout << "Total Company Payroll: " << hrManager.calcPayroll() << " EGP" << endl;
    cout << "===============================" << endl;

    // 6. نجرب نظام المشاريع والميزانية
    // هنخلي "Zaki" (المدير رقم 4) هو مدير المشروع
    Project p1(101, "Cairo Site", (Employee*)m4); 
    
    Budget b1(1, 10000.0); // ميزانية مواد بناء
    Budget b2(2, 5000.0);  // ميزانية نقل
    
    p1.addBudget(b1);
    p1.addBudget(b2);
    
    cout << "--- Project Details ---" << endl;
    p1.print();

    return 0;
}

