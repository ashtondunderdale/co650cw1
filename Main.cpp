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

        std::cout << "Enterprise Sales Management System\n";
        std::cout << "____________________________________________" << std::endl;
        std::cout << " 1 |  Customer Relations & Engagement\n";
        std::cout << " 2 |  Order Fulfillment & Processing\n";
        std::cout << " 3 |  Manage Inventory\n";
        std::cout << " 4 |  Manage Financial Accounts\n   |\n";
        std::cout << " 9 |  Exit Program\n\n";

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
