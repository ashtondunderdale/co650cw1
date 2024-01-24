#include <iostream>
#include "CustomerOperations.h"
#include "OrderOperations.h"
#include "InventoryOperations.h"
#include "AccountingOperations.h"

class SalesInterface {
public:
    void Run() {
        CustomerOperations::AddSampleCustomers(); // For testing, to remove.

        bool run = true;

        while (run) {
            run = DisplaySalesInterface();
        }
    }

    bool DisplaySalesInterface() {
        std::cout << "Welcome to the Enterprise Sales Management System\n\n\n 1 |  Customer Relations & Engagement\n 2 |  Order Fulfillment & Processing\n\n 3 |  Inventory Management\n\n 4 |  Manage Accounts \n\n\n\n 9 |  Exit Program\n\n";
        std::string interfaceInput;

        getline(std::cin, interfaceInput);
        system("CLS");

        if (interfaceInput == "1") {
            CustomerOperations::DisplayCustomerInterface();
        }
        else if (interfaceInput == "2") {
            OrderOperations::DisplayOrderInterface();
        }
        else if (interfaceInput == "3") {
            InventoryOperations::DisplayInventoryInterface();
        }
        else if (interfaceInput == "4") {
            AccountingOperations::DisplayAccountingInterface();
        }
        else if (interfaceInput == "9") {
            return false;
        }
    }
};

int main() {
    SalesInterface* interface = new SalesInterface();
    interface->Run();

    delete interface;

    return 0;
}

void CleanConsole() {
    std::cout << "\n\n\tPress Enter to return.";
    std::cin.get();
    system("CLS");
}
