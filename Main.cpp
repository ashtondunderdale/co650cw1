#include <iostream>

#include "CustomerOperations.h"
#include "Main.h"
#include "OrderOperations.h"
#include "InventoryOperations.h"


class SalesInterface {

    public:
        void Run() {
            CustomerOperations::AddSampleCustomers(); // For testing, to remove. 

            while (true) {
                DisplaySalesInterface();
            }
        }

    public:
        void DisplaySalesInterface() {
            std::cout << "Welcome to the Enterprise Sales Management System\n\n\n 1 |  Customer Relations & Engagement\n 2 |  Order Fulfillment & Processing\n\n 3 |  Inventory Management\n\n\n\n 9 |  Exit Program\n\n";
            std::string interfaceInput;

            getline(std::cin, interfaceInput);
            system("CLS");

            if (interfaceInput == "1") 
            {
                CustomerOperations::DisplayCustomerInterface();
            }
            else if (interfaceInput == "2")
            {
                OrderOperations::DisplayOrderInterface();
            }
            else if (interfaceInput == "3") 
            {
                InventoryOperations::DisplayInventoryInterface();
            }
            else if (interfaceInput == "9")
            {
                exit(0); 
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