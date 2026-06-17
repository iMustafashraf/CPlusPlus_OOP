#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Department;

class StaffMember {
protected:
	int employeeID;
	string name;
	string phone;
	string email;
	Department* dept; // dept-> departName (Reaching to whatever you want)
public:
	StaffMember() : employeeID(0), name(""), phone(""), email(""), dept(nullptr) {}
	void setStaff(int id, string nm, string phn, string eml){
		employeeID = id;
		name = nm;
		phone = phn;
		email = eml;
	}
	void setDepartment(Department* dep) {
		dept = dep;
	}

	void Print() {
		cout << "----------------------------------------\n";
		cout << "ID     : " << employeeID << "\n";
		cout << "Name   : " << name << "\n";
		cout << "Phone  : " << phone << "\n";
		cout << "Email  : " << email << "\n";
	}
	virtual double Pay() {
		return 0.0; // no salary for father class
	}

	virtual ~StaffMember() {}
};

class Staff {
private:
	vector<StaffMember*> staffList;

public:
	void addStaffMember(StaffMember* member) {
		staffList.push_back(member);
	}

	void print() {
		cout << "\n========================================\n";
		cout << "--- Global Company Staff List --- Total: " << staffList.size() << "\n";
		cout << "========================================\n";

		if (staffList.empty()) {
			cout << "The staff list is completely empty.\n";
		}
		else {
			for (int i = 0; i < staffList.size(); i++) {
				staffList[i]->Print();
			}
		}
		cout << "========================================\n";
	}
};

class Department {
private:
	int departID;
	string departName;
	vector<StaffMember*> stuff; // without (*) --> Object Slicing --> Take part only
public:
	Department(int id = 0, string name = "") : departID(id), departName(name) {}
	void addStaff(StaffMember* stff) {
		stuff.push_back(stff); 
		stff->setDepartment(this);
	}

	void print() {
		cout << "\n========== Department: " << departName << " =============\n";
		cout << "Department ID   : " << departID << "\n";
		cout << "Department Name : " << departName << "\n";

		if (stuff.empty()) {
			cout << "No employees in this department yet.\n";
		}
		else {
			cout << "Staff Name : \n";
			for (int i = 0; i < stuff.size(); i++) {
				stuff[i]->Print(); 
			}
		}
	}
};

class Employee : public StaffMember {
protected:
	string socialSecurityNumber;
public:
	void setSecurityNumber(string num) {
		socialSecurityNumber = num;
	}
	void Print() {
		StaffMember::Print();
		cout << "\n- Security Number : " << socialSecurityNumber << endl;
	}
};

class Volunteer : public StaffMember {
private:
	int amount;
public:
	Volunteer() : amount(0) {}
	void setVolunteer() {
		cout << "Give me amount : \n";
		int x; cin >> x;
		amount += x; // right ?
	}
	void Print() {
		StaffMember::Print();
		cout << "\n- Amount : " << amount << endl;
	}
	double Pay() override {
		return 0.0;
	}
};

class Salaried : public Employee {
public:
	Salaried() : salary(0.0) {}
	double salary;
	void setSalary(double slry) {
		salary = slry;
	}
	double Pay() override {
		return salary;
	}
};

class Hourly : public Employee {
private:
	double hoursWorked;
	double rate;
public:
	Hourly() : rate(0.0) {
		hoursWorked = 0.0;
	}
	void setRate(double rt) {
		rate = rt;
	}
	void addHours(int moreHours) {
		hoursWorked += moreHours;
	}
	double Pay() override{
		return rate * hoursWorked;
	}
};

class Commission : public Employee {
public:
	double target;
	void setTarget(double trgt) {
		target = trgt;
	}
	double Pay() override {
		return target * 0.05; // %5
	}
};

class Budget {
private:
	int id;
	double value;
public:
	Budget(int b_id = 0, double val = 0.0) : id(b_id), value(val) {}
	void increaseBudget(double amnt) {
		value += amnt;
	}
	void WithdrawBudget(double amnt) {
		if (value > amnt) {value -= amnt;}
		else { value = 0; }
	}
	double getValue() {
		return value;
	}
};

class Project {
private:
	int projectID;
	int total_budget;
	string location;
	Employee* manager;
	double currentCost;
	vector<Budget> budgetlist;
public:
	Project(int p_id = 0) : projectID(p_id), currentCost(0.0), total_budget(0) {
		manager = nullptr; 
	}
	void addLocation(string loc) { location = loc; }
	void addManager(Employee* e) { manager = e; }
	void addBudget(Budget bdg) { budgetlist.push_back(bdg); }
	double getTotalBudget() {
		total_budget = 0;
		for (int i = 0; i < budgetlist.size(); i++) {
			total_budget += budgetlist[i].getValue();
		}
		return total_budget;
	}
	void spendFromBudget(double value) {
		if (!budgetlist.empty()) {
			budgetlist[0].WithdrawBudget(value); 
			currentCost += value;
		}
		else { cout << "No budget available to spend from!\n"; }
	}
	void Print() {
		cout << "\n========================================\n";
		cout << ":::::::::::: PROJECT DETAILS :::::::::::\n";
		cout << "========================================\n";
		cout << "Project ID   : " << projectID << "\n";
		cout << "Location     : " << location << "\n";
		cout << "Current Cost : " << currentCost << " USD\n";
		cout << "Total Budget : " << getTotalBudget() << " USD\n";

		if (manager != nullptr) {
			cout << "--- Project Manager Info ---\n";
			manager->Print(); 
		}
		else {
			cout << "Project Manager: No manager assigned yet.\n";
		}
		cout << "========================================\n";
	}
};

int main() {
	// --------------- Implementation ------------------

	Department Programming(1, "Programming");

	Salaried mahmoud;
	mahmoud.setStaff(112233, "mahmoud", "011245831", "mahmoudm3aleem@gmail.com");
	mahmoud.setSecurityNumber("SSN-111");
	mahmoud.setSalary(8000.0);

	Salaried Kamal;
	Kamal.setStaff(445566, "Kamal", "010999888", "kamal@gmail.com");
	Kamal.setSecurityNumber("SSN-222");
	Kamal.setSalary(7500.0);

	Hourly Sarah;
	Sarah.setStaff(778899, "Sarah", "012333444", "sarah@gmail.com");
	Sarah.setSecurityNumber("SSN-333");
	Sarah.setRate(30.0);
	Sarah.addHours(120);

	Programming.addStaff(&mahmoud);
	Programming.addStaff(&Kamal);
	Programming.addStaff(&Sarah);

	// ----------------- Budget & Project ------------------
	Budget InnerBank(10, 5500.0);
	InnerBank.WithdrawBudget(1500.0); // Leaves 4000.0

	Project TotalBank(99);
	TotalBank.addLocation("Cairo HQ Office");
	TotalBank.addBudget(InnerBank);

	TotalBank.addManager(&mahmoud);

	// ----------------- Calculations ------------------
	double mahmoudSalary = mahmoud.Pay();
	double kamalSalary = Kamal.Pay();
	double sarahSalary = Sarah.Pay();

	cout << "\n========================================\n";
	cout << "        FINANCIAL TRANSACTIONS          \n";
	cout << "========================================\n";

	cout << "-> Paying Manager (mahmoud): " << mahmoudSalary << " USD\n";
	TotalBank.spendFromBudget(mahmoudSalary);

	cout << "-> Paying Developer (Kamal): " << kamalSalary << " USD\n";
	TotalBank.spendFromBudget(kamalSalary);

	cout << "-> Paying Developer (Sarah): " << sarahSalary << " USD\n";
	TotalBank.spendFromBudget(sarahSalary);

	// ----------------- Global Team -----------------
	Staff MyTeam;
	MyTeam.addStaffMember(&mahmoud);
	MyTeam.addStaffMember(&Kamal);
	MyTeam.addStaffMember(&Sarah);

	// ----------------- Reports Display -----------------
	MyTeam.print();
	Programming.print();
	TotalBank.Print();
}
