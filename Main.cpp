#include <iostream>

#include "CustomerOperations.h"


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
    std::cout << "Main Sales Interface\n\n 1 |  Customers\n 2 |  Orders  \n\n";
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
}