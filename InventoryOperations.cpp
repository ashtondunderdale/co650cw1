#include <iostream>
#include <string>

#include "InventoryOperations.h"

void DisplayInventoryInterface()
{
    std::cout << "Company Sales Interface\n\n 1 |  Customers\n 2 |  Orders  \n\n";
    std::string inventoryInterfaceInput;

    getline(std::cin, inventoryInterfaceInput);
    system("CLS");

    if (inventoryInterfaceInput == "1")
    {
        
    }

}