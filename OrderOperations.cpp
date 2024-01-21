#include <iostream>
#include <list>

#include "OrderOperations.h"
#include "CustomerOperations.h"
#include "Order.h"


std::list<Order> orders;


void DisplayOrderInterface()
{
    std::cout << "Order Interface\n\n 1 |  Add Order\n 2 |  View Orders\n 3 |  Search Orders\n 4 |  Cancel Order\n\n";

    std::string orderInterfaceInput;
    getline(std::cin, orderInterfaceInput);
    if (orderInterfaceInput == "1")
    {
        AddOrder();
    }
    else if (orderInterfaceInput == "2")
    {
        ViewOrders();
    }
    else if (orderInterfaceInput == "3")
    {
        SearchOrders();
    }
    else if (orderInterfaceInput == "4")
    {
        CancelOrder();
    }
    CleanConsole(); 
}


void AddOrder() 
{
    for (auto const& customer : customers) 
    {
        std::string IsActiveString = "Inactive"; 

        if (customer.IsActive) 
        {
            IsActiveString = "Active"; 
        }

        std::cout << "\n" << "ID      |\t" << customer.ID << "\n"; 
        std::cout << "NAME    |\t" << customer.Name << "\n"; 
        std::cout << "ADDRESS |\t" << customer.DeliveryAddress << "\n"; 
        std::cout << "CONTACT |\t" << customer.Contact << "\n"; 
        std::cout << "STATUS  |\t" << IsActiveString << "\n"; 
    }

    std::cout << "\nSelect a customer (ID) for the order" << std::endl;

    std::string selectedCustomerInput;
    std::cin >> selectedCustomerInput;

    for (auto& customer : customers) 
    {
        if (customer.ID == selectedCustomerInput) 
        {
            std::cout << "\nAdded Order to '" << customer.Name << "'." << std::endl;
            getchar();
            return;
        }
    }
    std::cout << "\nA customer with that ID does not exist." << std::endl;
    getchar();
}

void ViewOrders()
{

}

void SearchOrders()
{

}

void CancelOrder()
{

}