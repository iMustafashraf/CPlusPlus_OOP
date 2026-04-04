#include "Sales.h"
#include <iostream>

using namespace std;

int main() {
    product laptop(101, "LPT-001", "Gaming Laptop", 1500.0, 1);
    stock warehouse(1, 50);
    warehouse.AddStock(101, 10);

    company myComp(500, "0123456789", "Cairo", "Tech Solutions");

    orderItem item1(101, "Gaming Laptop", 1500.0, 1450.0, 2);
    ++item1;

    order myOrder(1, 202401, 20240520, 4350.0);

    cash paymentMethod(4350.0, "2024-05-20", 4350.0);

    transaction trans("2024-05-20");
    trans += make_pair(ref(myOrder), ref(paymentMethod));

    cout << "\n--- Summary ---" << endl;
    cout << myComp.Print() << endl;
    cout << myOrder << endl;
    paymentMethod.Pay();

    return 0;
}
