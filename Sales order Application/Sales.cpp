#include "Sales.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// ==========================================
// class: product
// ==========================================
product::product(int ID, string num, string n, double p, int t) 
    : id(ID), number(num), name(n), price(p), type(t) {}

void product::Update() {
    int choice;
    cout << "--- Update Product (ID: " << id << ") ---" << endl;
    cout << "1. Update Name (Current: " << name << ")" << endl;
    cout << "2. Update Number (Current: " << number << ")" << endl;
    cout << "3. Update Price (Current: " << price << ")" << endl;
    cout << "4. Update Type (Current: " << type << ")" << endl;
    cout << "0. Exit Update" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter new name: ";
            cin.ignore(); 
            getline(cin, name);
            break;
        case 2:
            cout << "Enter new number: ";
            cin >> number;
            break;
        case 3:
            cout << "Enter new price: ";
            cin >> price;
            break;
        case 4:
            cout << "Enter new type: ";
            cin >> type;
            break;
        case 0:
            cout << "Update cancelled." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    
    if (choice >= 1 && choice <= 4) {
        cout << "Product updated successfully!" << endl;
    }
}

// Printing
ostream& operator<<(ostream& out, product& s) {
    out << "Product [ID: " << s.id << ", Name: " << s.name << ", Price: " << s.price << "]";
    return out;
}

// Input
istream& operator>>(istream& in, product& s) {
    cout << "Enter ID: "; in >> s.id;
    cout << "Enter Name: "; in >> s.name;
    cout << "Enter Price: "; in >> s.price;
    return in;
}

// ==========================================
// class: stock
// ==========================================
stock::stock(int ID, int c) 
    : id(ID), count(c) {}

    void stock::AddStock(int product_id, int quantity) {
    count += quantity;
    cout << "Added " << quantity << " items to stock." << endl;
}

void stock::UpdateStock(int product_id, int quantity) {
    this->count = quantity; 
    cout << "Stock count updated to: " << count << endl;
}

void stock::Delete(int product_id) {
    count = 0;
    cout << "Stock cleared for product ID: " << product_id << endl;
}

int stock::GetQuantity(int product_id) {
    return count;
}

ostream& operator<<(ostream& out, stock& s) {
    out << "Stock ID: " << s.id << " | Total Items: " << s.count << endl;
    out << "--- Products in Stock ---" << endl;
    
    for (int i = 0; i < s.ProductBox.size(); i++) {
        out << s.ProductBox[i] << endl; 
    }
    return out;
}

// الإدخال - Input Stock
istream& operator>>(istream& in, stock& s) {
    cout << "Enter Stock ID: ";
    in >> s.id;
    cout << "Enter Initial Count: ";
    in >> s.count;
    return in;
}
// ==========================================
// class: orderItem
// ==========================================
orderItem::orderItem(int ID, string n, double p, double sp, double q) 
    : product(ID, "NUM", n, p, 0), sale_price(sp), quantity(q) {}

    void orderItem::UpdateQuantity(int new_quantity) {
    if (new_quantity >= 0) {
        quantity = new_quantity;
    }
}

orderItem& orderItem::operator++() {
    quantity++;
    return *this;
}

orderItem& orderItem::operator--() {
    if (quantity > 0) quantity--;
    return *this;
}

void orderItem::operator+=(int n) {
    if (n > 0) quantity += n;
}

void orderItem::operator-=(int n) {
    if (quantity >= n) {
        quantity -= n;
    } else {
        quantity = 0; 
    }
}

// ==========================================
// class: payment
// ==========================================
payment::payment(string date, double amt) 
    : paid_date(date), amount(amt) {}

        double payment::Pay() {
    cout << "Processing payment of: " << amount << " on date: " << paid_date << endl;
    return amount;
}

string payment::Update() {
    cout << "Enter new payment date (Current: " << paid_date << "): ";
    cin >> paid_date;
    cout << "Enter new amount (Current: " << amount << "): ";
    cin >> amount;
    return "Payment updated to " + to_string(amount) + " on " + paid_date;
}

// ==========================================
// class: customer
// ==========================================
customer::customer(int ID, string ph) 
    : id(ID), phone(ph) {}

string customer::Print() {
    return "ID: " + to_string(id) + " | Phone: " + phone;
}

ostream& operator<<(ostream& out, const customer& c) {
    customer& temp = const_cast<customer&>(c);
    out << temp.Print();
    return out;
}

istream& operator>>(istream& in, customer& c) {
    cout << "Enter ID: "; in >> c.id;
    cout << "Enter Phone: "; in >> c.phone;
    return in;
}

// ==========================================
// class: company
// ==========================================
company::company(int ID, string ph, string l, string cn) 
    : customer(ID, ph), location(l), company_name(cn) {}

    string company::Print() {
    return customer::Print() + " | Company: " + company_name + " | Location: " + location;
}

// ==========================================
// class: person
// ==========================================
person::person(int ID, string ph, string ba, string full) 
    : customer(ID, ph), billing_address(ba), fullname(full) {}

    string person::Print() {
    return customer::Print() + " | Name: " + fullname + " | Address: " + billing_address;
}

// ==========================================
// class: customers
// ==========================================
customers::customers(int c) 
    : count(c) {}

    void customers::AddCustomer() {
    count++;
    cout << "Customer added. Total: " << count << endl;
}

void customers::EditCustomer() {
    cout << "Editing customer logic..." << endl;
}

void customers::DeleteCustomer() {
    if (count > 0) count--;
    cout << "Customer deleted. Total: " << count << endl;
}

void customers::Print() {
    cout << "Total customers in system: " << count << endl;
}

// ==========================================
// class: credit
// ==========================================
credit::credit(string num, int expire, string typ, string data, double amt) 
    : payment(data, amt), number(num), expireDate(expire), type(typ) {}

// ==========================================
// class: cash
// ==========================================
cash::cash(double cv, string d, double a) 
    : payment(d, a), cashValue(cv) {}

// ==========================================
// class: check
// ==========================================
check::check(string n, string BnkId, string data, double amt) 
    : payment(data, amt), name(n), Bank_id(BnkId) {}

// ==========================================
// class: order
// ==========================================
order::order(int ID, int num, int dta, double t) 
    : id(ID), number(num), date(dta), total(t) {}

    void order::CreateOrder() {
    cout << "Order ID: " << id << " created." << endl;
}

void order::UpdateOrder(int order_id, int status) {
    if (this->id == order_id) {
        cout << "Order " << order_id << " status updated to code: " << status << endl;
    }
}

void order::EditOrder(int order_id) {
    if (this->id == order_id) {
        cout << "Enter new total for order " << id << ": ";
        cin >> total;
    }
}

ostream& operator<<(ostream& out, const order& o) {
    out << "Order ID: " << o.id << " | Number: " << o.number << " | Date: " << o.date << " | Total: " << o.total;
    return out;
}

istream& operator>>(istream& in, order& o) {
    cout << "Enter Order ID, Number, Date, Total: ";
    in >> o.id >> o.number >> o.date >> o.total;
    return in;
}

// ==========================================
// class: transaction
// ==========================================
transaction::transaction(string t_data) 
    : transaction_date(t_data) {}

int transaction::GetOrder(int order_id) {
    return order_id;
}

ostream& operator<<(ostream& out, const transaction& t) {
    out << "Transaction Date: " << t.transaction_date;
    return out;
}

transaction& transaction::operator+=(pair<order&, payment&> op) {
    cout << "Linking Order (ID: " << op.first << ") with Payment." << endl;
    return *this;
}
