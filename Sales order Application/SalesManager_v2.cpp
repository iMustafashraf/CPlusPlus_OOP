#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

class Product {
private:
    int id;
    std::string number;
    std::string name;
    double price;
    int type;
public:
    Product(int ID, std::string num, std::string nam, double prc, int tp)
        : id(ID), number(num), name(nam), price(prc), type(tp) {
    }

    int getID() {
        return id;
    }

    friend std::istream& operator >>(std::istream& in, Product& p);
    friend std::ostream& operator <<(std::ostream& out, const Product& p);

    void Update() {
        std::cout << "========================================\n";
        std::cout << "--- Update Product Information ---\n";
        std::cout << "1. Update Product Number\n";
        std::cout << "2. Update Product Name\n";
        std::cout << "3. Update Product Price\n";
        std::cout << "4. Update Product Type\n";
        std::cout << "Enter your choice (1-4): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter new Product Number: ";
            std::cin >> number;
            std::cout << "Product Number updated successfully!\n";
            break;
        }
        case 2: {
            std::cout << "Enter new Product Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Product Name updated successfully!\n";
            break;
        }
        case 3: {
            std::cout << "Enter new Product Price: ";
            std::cin >> price;
            std::cout << "Product Price updated successfully!\n";
            break;
        }
        case 4: {
            std::cout << "Enter new Product Type: ";
            std::cin >> type;
            std::cout << "Product Type updated successfully!\n";
            break;
        }
        default:
            std::cout << "Invalid choice! No changes were made.\n";
            break;
        }
        std::cout << "========================================\n";
    }
};

std::istream& operator >>(std::istream& in, Product& p) {
    std::cout << "Enter Product ID, Number, Name, Price, Type:\n";
    in >> p.id >> p.number;
    in.ignore();
    std::getline(in, p.name);
    in >> p.price >> p.type;
    return in;
}

std::ostream& operator <<(std::ostream& out, const Product& p) {
    out << "Product ID: " << p.id << " | Name: " << p.name << " | Price: " << p.price << " EGP";
    return out;
}

class Stock {
private:
    int id;
    int count;
    struct StockItem {
        Product* product;
        int quantity;
    };
    std::vector<StockItem> storage;
public:
    Stock() : id(0), count(0) {}

    friend std::istream& operator >>(std::istream& in, Stock& s);
    friend std::ostream& operator <<(std::ostream& out, const Stock& s);

    void setStorage_id(int ID) {
        id = ID;
    }

    void addStock(int product_id, int quantity, Product* p) {
        storage.push_back({ p, quantity });
        count++;
    }

    void updateStock(int product_id, int quantity) {
        for (size_t i = 0; i < storage.size(); i++) {
            if (storage[i].product->getID() == product_id) {
                storage[i].product->Update();
                break;
            }
        }
    }

    void Delete(int product_id) {
        for (size_t i = 0; i < storage.size(); i++) {
            if (storage[i].product->getID() == product_id) {
                std::swap(storage[i], storage[storage.size() - 1]);
                storage.pop_back();
                count--;
                break;
            }
        }
    }

    int GetQuantity(int product_id) {
        for (size_t i = 0; i < storage.size(); i++) {
            if (storage[i].product->getID() == product_id) {
                return storage[i].quantity;
            }
        }
        return 0;
    }
};

std::istream& operator >>(std::istream& in, Stock& s) {
    std::cout << "Enter Stock details : id, count: ";
    in >> s.id >> s.count;
    return in;
}

std::ostream& operator <<(std::ostream& out, const Stock& s) {
    out << "============ Stock ID: " << s.id << " ============\n";
    for (size_t i = 0; i < s.storage.size(); i++) {
        out << *(s.storage[i].product) << " | Quantity: " << s.storage[i].quantity << "\n";
    }
    return out;
}

class Customer {
private:
    int id;
    std::string phone;
protected:
    void PrintCSInfo() {
        std::cout << "\n ----------{ Customer info }------------\n";
        std::cout << "Customer ID : " << id << std::endl;
        std::cout << "Customer number : " << phone << std::endl;
    }
public:
    Customer(int ID, std::string phn) : id(ID), phone(phn) {}
    virtual ~Customer() {} // Virtual destructor for safe polymorphism inheritance

    friend std::istream& operator >>(std::istream& in, Customer& CS);
    friend std::ostream& operator <<(std::ostream& out, const Customer& CS);

    void SetCSID(int ID) { id = ID; }
    void SetCSPhone(std::string phn) { phone = phn; }
    int getID() { return id; }

    void UpdateCS() {
        std::cout << "========================================\n";
        std::cout << "--- Update Customer Information ---\n";
        std::cout << "1. Update Customer ID\n";
        std::cout << "2. Update Customer Phone Number\n";
        std::cout << "Enter your choice (1-2): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter new Customer ID: ";
            std::cin >> id;
            std::cout << "Customer ID updated successfully!\n";
            break;
        }
        case 2: {
            std::cout << "Enter new Customer Phone Number: ";
            std::cin >> phone;
            std::cout << "Customer Phone Number updated successfully!\n";
            break;
        }
        default:
            std::cout << "Invalid choice! No changes were made.\n";
            break;
        }
        std::cout << "========================================\n";
    }
    virtual void Print() = 0;
};

std::istream& operator >>(std::istream& in, Customer& CS) {
    in >> CS.id >> CS.phone;
    return in;
}

std::ostream& operator <<(std::ostream& out, const Customer& CS) {
    out << "ID : " << CS.id << ", Phone : " << CS.phone << std::endl;
    return out;
}

class Company : public Customer {
private:
    std::string location;
    std::string company_name;
public:
    Company(int ID, std::string phn, std::string loc, std::string comp)
        : Customer(ID, phn), location(loc), company_name(comp) {
    }

    void setLocat(std::string loc) { location = loc; }
    void setCompName(std::string comp) { company_name = comp; }

    void Print() override {
        std::cout << "\n ----------{ Company Customer info }------------\n";
        Customer::PrintCSInfo();
        std::cout << "Customer Location     : " << location << std::endl;
        std::cout << "Customer Company Name : " << company_name << std::endl;
        std::cout << "----------------------------------------\n";
    }
};

class Person : public Customer {
private:
    std::string billing_address;
    std::string fullname;
public:
    Person(int ID, std::string phn, std::string addr, std::string name)
        : Customer(ID, phn), billing_address(addr), fullname(name) {
    }

    void setBillingAddress(std::string addr) { billing_address = addr; }
    void setFullname(std::string name) { fullname = name; }

    void Print() override {
        std::cout << "\n ----------{ Person Customer info }------------\n";
        Customer::PrintCSInfo();
        std::cout << "Billing Address : " << billing_address << std::endl;
        std::cout << "Full Name       : " << fullname << std::endl;
        std::cout << "----------------------------------------\n";
    }
};

class Customers {
private:
    int count;
    std::vector<Customer*> customers;
public:
    Customers() : count(0) {}
    ~Customers() {
        for (auto c : customers) delete c;
    }

    void addCustomer(Customer* cs) {
        customers.push_back(cs);
        count++;
    }

    void EditCustomer(int ID) {
        for (size_t i = 0; i < customers.size(); i++) {
            if (customers[i]->getID() == ID) {
                customers[i]->UpdateCS();
                break;
            }
        }
    }

    void DeleteCustomer(int ID) {
        for (size_t i = 0; i < customers.size(); i++) {
            if (customers[i]->getID() == ID) {
                delete customers[i];
                std::swap(customers[i], customers[customers.size() - 1]);
                customers.pop_back();
                count--;
                break;
            }
        }
    }

    void Print() {
        for (size_t i = 0; i < customers.size(); i++) {
            std::cout << "===============[ Customers log ]==============\n";
            customers[i]->Print();
            std::cout << std::endl;
        }
        std::cout << "====================[ log ended ]====================\n";
    }
};

class OrderItem {
private:
    double sale_price;
    double quantity;
    Product* productItem;
public:
    OrderItem(Product* prod, double qn, double price)
        : sale_price(price), quantity(qn), productItem(prod) {
    }

    void UpdateQuantity(double qn, Stock& currStock) {
        if (!productItem) return;
        int p_id = productItem->getID();
        int availableInStock = currStock.GetQuantity(p_id);

        if (availableInStock >= qn) { quantity = qn; }
        else { std::cout << "Updating Failed, Try Again after 2 years.. :)\n"; }
    }

    int getProductID() {
        return productItem ? productItem->getID() : -1;
    }

    void setSalePrice(double pr) { sale_price = pr; }
    double getItemTotal() { return sale_price * quantity; }

    void operator ++() { quantity++; }
    void operator --() { quantity--; }
    void operator +=(int value) { quantity += value; }
    void operator -=(int value) { quantity -= value; }

    Product* getProduct() const { return productItem; }
    double getQuantity() const { return quantity; }
};

enum class OrderStatus {
    NEW,
    HOLD,
    PAID,
    CANCELED
};

class Order {
public:
    struct time {
        int day;
        int months;
        int year;
    };
private:
    int id;
    int number;
    double total;
    time date;
    OrderStatus Status;
    std::vector<OrderItem*> items;
public:
    Order() : id(0), number(0), total(0.0), date({ 1,1,2026 }), Status(OrderStatus::NEW) {}
    Order(int ID, int num, time t, OrderStatus st)
        : id(ID), number(num), total(0.0), date(t), Status(st) {
    }
    ~Order() {
        for (auto item : items) delete item;
    }

    void CreateOrder(int ID, int num, double totl, time t, OrderStatus st) {
        id = ID;
        number = num;
        total = totl;
        date = t;
        Status = st;
    }

    void UpdateOrder(int order_id, int status) {
        if (this->id == order_id) {
            Status = static_cast<OrderStatus>(status);
        }
    }

    void EditOrder(int order_id, int new_number, double new_total, time new_date) {
        if (this->id == order_id) {
            number = new_number;
            total = new_total;
            date = new_date;
            std::cout << "Order " << order_id << " updated successfully!\n";
        }
        else {
            std::cout << "Error: Order ID mismatch! No changes made.\n";
        }
    }

    int getOrderID() {
        return id;
    }

    void addItem(OrderItem* item) {
        items.push_back(item);
        total += item->getItemTotal();
    }

    double calculateTotal() {
        total = 0;
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i]) total += items[i]->getItemTotal();
        }
        return total;
    }

    friend std::istream& operator >>(std::istream& in, Order& o);
    friend std::ostream& operator <<(std::ostream& out, const Order& o);
};

std::istream& operator >>(std::istream& in, Order& o) {
    std::cout << "Enter Order ID, Number: ";
    in >> o.id >> o.number;
    std::cout << "Enter Date (day month year): ";
    in >> o.date.day >> o.date.months >> o.date.year;

    int status_input;
    std::cout << "Enter Status (0:NEW, 1:HOLD, 2:PAID, 3:CANCELED): ";
    in >> status_input;
    o.Status = static_cast<OrderStatus>(status_input);

    return in;
}

std::ostream& operator <<(std::ostream& out, const Order& o) {
    out << "ID : " << o.id << ", Number : " << o.number << ", Total : " << o.total
        << ", Date : " << o.date.day << "/" << o.date.months << "/" << o.date.year
        << ", Status : " << static_cast<int>(o.Status) << "\n";

    if (!o.items.empty()) {
        out << "--- Order Items ---\n";
        for (size_t i = 0; i < o.items.size(); ++i) {
            if (o.items[i] && o.items[i]->getProduct()) {
                out << "   -> " << o.items[i]->getProduct()->getID() << " | Quantity: " << o.items[i]->getQuantity() << "\n";
            }
        }
    }
    return out;
}

class Payment {
protected:
    struct date {
        int day;
        int months;
        int year;
    };
private:
    date paid_date;
    double amount;
public:
    Payment() : paid_date({ 1,1,2026 }), amount(0.0) {}

    double Pay(double addition) {
        std::cout << "Enter payment date (day month year): ";
        std::cin >> paid_date.day >> paid_date.months >> paid_date.year;
        amount += addition;
        return amount;
    }

    std::string Update() {
        std::cout << "Enter updated amount: ";
        std::cin >> amount;
        return "Payment amount updated successfully!";
    }
};

class Credit : public Payment {
public:
    std::string number;
    std::string expireDate;
    std::string type;
};

class Cash : public Payment {
public:
    double cashValue;
};

class Check : public Payment {
public:
    std::string name;
    std::string Bank_ID;
};

class Transaction {
private:
    struct date {
        int day;
        int months;
        int year;
    };
    date Transaction_date;
    Order* curr_order;
public:
    Transaction() : Transaction_date({ 1,1,2026 }), curr_order(nullptr) {}

    friend std::ostream& operator <<(std::ostream& out, const Transaction& t);

    // تصحيح الـ operator += ليعمل كـ member function لتفادي مشاكل الـ Memory & Dangling pointer
    Transaction& operator +=(Order& o) {
        this->curr_order = &o;
        this->Transaction_date = { 18, 6, 2026 };
        return *this;
    }

    Order* getOrder(int order_id) {
        if (curr_order && curr_order->getOrderID() == order_id) {
            return curr_order;
        }
        else {
            std::cout << "The ID doesn't match! Check it.\n";
            return nullptr;
        }
    }
};

std::ostream& operator <<(std::ostream& out, const Transaction& t) {
    out << "Transaction Date: " << t.Transaction_date.day << "/" << t.Transaction_date.months << "/" << t.Transaction_date.year << std::endl;
    if (t.curr_order) {
        out << "Order Total: " << t.curr_order->calculateTotal() << std::endl;
    }
    else {
        out << "No Order attached to this transaction." << std::endl;
    }
    return out;
}

// ======================= { Main function for testing } =======================
int main() {
    std::cout << "================== [ START TESTING SYSTEM ] ==================\n\n";

    std::cout << "[1] Testing Product:\n";
    Product p1(101, "P-1001", "Gaming Laptop", 35000.0, 1);
    Product p2(102, "P-1002", "Mechanical Keyboard", 2500.0, 2);
    std::cout << p1 << "\n" << p2 << "\n\n";

    std::cout << "[2] Testing Stock:\n";
    Stock mainStock;
    mainStock.setStorage_id(5001);
    mainStock.addStock(101, 50, &p1);
    mainStock.addStock(102, 120, &p2);
    std::cout << mainStock << "\n";

    std::cout << "[3] Testing Customers Polymorphism:\n";
    Customers customersManager;
    customersManager.addCustomer(new Company(1, "01011111111", "Cairo, Egypt", "TechCorp"));
    customersManager.addCustomer(new Person(2, "01222222222", "Alexandria, Egypt", "Ahmed Ali"));
    customersManager.Print();

    std::cout << "[4] Testing Order and OrderItems:\n";
    Order myOrder(9001, 7432, { 18, 6, 2026 }, OrderStatus::NEW);

    OrderItem* item1 = new OrderItem(&p1, 2, 34500.0); 
    OrderItem* item2 = new OrderItem(&p2, 5, 2500.0);  

    myOrder.addItem(item1);
    myOrder.addItem(item2);

    std::cout << myOrder << "\n";
    std::cout << "Calculated Order Total: " << myOrder.calculateTotal() << " EGP\n\n";

    std::cout << "[5] Testing Payments & Transactions:\n";
    Cash cashPayment;
    cashPayment.cashValue = 81500.0;

    Transaction trans;
    trans += myOrder;

    std::cout << trans << "\n";

    std::cout << "================== [ ALL TESTS COMPLETED SUCCESSFULLY ] ==================\n";
    return 0;
}
