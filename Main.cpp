#include <iostream>

#include "CustomerOperations.h"
#include "Main.h"


class SalesInterface {

    public:
        void Run() {
            AddSampleCustomers(); // For testing, to remove.

            while (true) {
                DisplaySalesInterface();
            }
        }

    private:
        void DisplaySalesInterface() {
            std::cout << "Welcome to the Enterprise Sales Management System\n\n\n 1 |  Customer Relations & Engagement\n 2 |  Order Fulfillment & Processing\n\n 3 |  Inventory Management\n\n";
            std::string interfaceInput;

            getline(std::cin, interfaceInput);
            system("CLS");

            if (interfaceInput == "1") {
                DisplayCustomerInterface();
            }
            else if (interfaceInput == "2") {
                DisplayOrderInterface();
            }
            else if (interfaceInput == "3") {
                DisplayInventoryInterface();
            }
        }
};


int main() {
    SalesInterface interface;
    interface.Run();

    return 0;
}


void CleanConsole() 
{
    std::cout << "\n\n\tPress Enter to return.";
    getchar();
    system("CLS");
}