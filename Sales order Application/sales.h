#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

enum OrderStatus {
    NEW = 0,
    HOLD = 1,
    PAID = 2,
    CANCELED = 3
};

class product {
private: 
    int id;
    string number;
    string name;
    double price;
    int type;
public:
    product(int ID, string num, string n, double p, int t);
    void Update();
    friend ostream& operator<<(ostream& out, product& s);
    friend istream& operator>>(istream& in, product& s);
};

class stock{
private:
    int id;
    int count ;
    vector<product> ProductBox ; // when I will use this ?
public:
    stock (int ID, int c = 0);
    void AddStock(int product_id, int quantity);
    void UpdateStock(int product_id, int quantity);
    void Delete(int product_id);
    int GetQuantity(int product_id);
    // output
    friend ostream& operator<<(ostream& out, stock& s);
    // Input
    friend istream& operator>>(istream& in, stock& s);
};

class orderItem : public product{
private:
    double sale_price;
    double quantity;
public:
orderItem(int ID, string n, double p, double sp = 0.00, double q = 0.00);    void UpdateQuantity(int new_quantity);
    orderItem& operator++();
    orderItem& operator--();
    
    void operator+=(int n);
    void operator-=(int n);
};

class payment {
protected:
    string paid_date;
    double amount;
public:
    payment(string date = "", double amt = 0.0);
    double Pay();
    string Update();
};

class customer{
private:
    int id;
    string phone;
protected:
    string Print();
public:
    customer(int ID, string ph);
    friend ostream& operator<<(ostream& out, const customer& c);
    friend istream& operator>>(istream& in, customer& c);
};

class company : public customer{
private:
    string location;
    string company_name;
public:
    company(int ID, string ph, string l, string cn);    string Print(); 
};
class person : public customer{
private:
    string billing_address;
    string fullname;
public:
    person(int ID, string ph, string ba, string full);
    string Print();
};


class customers{
private:
    int count;
public:
    customers(int c);
    void AddCustomer();
    void EditCustomer();
    void DeleteCustomer();
    void Print();
};

class credit : public payment {
public: 
    string number;
    int expireDate;
    string type;
    credit(string num, int expire, string typ, string data, double amt);

};
class cash : public payment{
public: 
    double cashValue;
    cash(double cv, string d, double a);
};
class check : public payment{
public: 
    string name;
    string Bank_id;
    check(string n, string BnkId, string data, double amt);
};

class order{
private:
    int id;
    int number;
    int date;
    double total;
public: 
    order(int ID, int num, int dta, double t);
    void CreateOrder();
    void UpdateOrder(int order_id, int status);
    void EditOrder(int order_id);
    friend ostream& operator<<(ostream& out, const order& o);
    friend istream& operator>>(istream& in, order& o);
};

class transaction{
private:
    string transaction_date;
public:
    transaction(string t_data);
    int GetOrder(int order_id);
    friend ostream& operator<<(ostream& out, const transaction& t);
    transaction& operator+=(pair<order&, payment&> op);
};
