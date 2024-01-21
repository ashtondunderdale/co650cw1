#include <iostream>

#include "CustomerOperations.h"
#include "Main.h"


int main()
{
    AddSampleCustomers(); // For testing, to remove.

    while (true)
    {
        DisplaySalesInterface();
    }
}


void DisplaySalesInterface()
{
    std::cout << "Company Sales Interface\n\n 1 |  Customers\n 2 |  Orders\n\n 3 |  Inventory\n\n";
    std::string interfaceInput;

    getline(std::cin, interfaceInput);
    system("CLS");

    if (interfaceInput == "1")
    {
        DisplayCustomerInterface();
    }
    else if (interfaceInput == "2")
    {
        DisplayOrderInterface();
    }
    else if (interfaceInput == "3")
    {
        DisplayInventoryInterface();
    }
}


void CleanConsole() 
{
    std::cout << "\n\n\tPress Enter to return.";
    getchar();
    system("CLS");
}