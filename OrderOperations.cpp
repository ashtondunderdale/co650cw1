#include <iostream>
#include <list>
#include <random>

#include "OrderOperations.h"
#include "CustomerOperations.h"
#include "Order.h"
#include "Stock.h"


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
            while (true) 
            {
                for (auto& stock : stockData) 
                {
                    std::cout << "\n\n" << stock.ID << std::endl;
                    std::cout << stock.Name << std::endl;
                }

                std::cout << "Choose Stock to add to order" << std::endl;

                std::string ;
            }



            Order order(
                GenerateOrderID()
            );

            customer.customerOrders.push_back(order);

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
    for (auto& customer : customers)
    {
        std::cout << "\n\n" << customer.Name << std::endl;

        for (auto& order : customer.customerOrders) 
        {
            std::cout << order.ID;
        }
    }
    getchar();
}

void SearchOrders()
{

}

void CancelOrder()
{

}

std::string GenerateOrderID() {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int sequenceLength = 16;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

    std::string randomSequence;

    for (int i = 0; i < sequenceLength; ++i) {
        randomSequence += characters[distribution(generator)];
    }

    return randomSequence;
}