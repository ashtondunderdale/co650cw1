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
            std::vector<Stock> stockToOrder; 

            while (true) 
            {
                int iteration = 1;

                for (auto& stock : stockData) 
                {
                    std::cout << "Stock Index | " << iteration << std::endl;
                    std::cout << "\n" << stock.ID << std::endl;
                    std::cout << stock.Name << "\n\n" << std::endl;

                    iteration++;
                }

                std::cout << "\n\nChoose Stock Index to add to order, or enter '0' to finish order." << std::endl;

                int stockSelectionInput;
                std::cin >> stockSelectionInput; 

                if (stockSelectionInput == 0) 
                {
                    std::cout << "\nFinished stock order." << std::endl;

                    Order order(
                        GenerateOrderID(),
                        stockToOrder 
                    );

                    customer.customerOrders.push_back(order);

                    getchar();
                    return;
                }

                Stock selectedStock = stockData[stockSelectionInput - 1]; 
                std::cout << "\nChosen stock: '" << selectedStock.Name << "'." << std::endl;

                int selectedStockQuantity;
                std::cout << "\n\nEnter stock amount" << std::endl;
                std::cin >> selectedStockQuantity;

                Stock orderStock(
                    stockData[stockSelectionInput - 1].ID,
                    stockData[stockSelectionInput - 1].Name,
                    stockData[stockSelectionInput - 1].Quantity,
                    selectedStockQuantity
                );

                stockToOrder.push_back(orderStock);

                std::cout << "\nAdded " << selectedStockQuantity << " '" << selectedStock.Name << "' to order." << std::endl;

                getchar();
                getchar(); 
            }

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

        for (auto& customerOrder : customer.customerOrders) 
        {
            std::cout << "\n\tOrder " << customerOrder.ID << std::endl;

            for (auto& stock : customerOrder.OrderStock) 
            {
                std::cout << "\t" << "\t" << stock.ID;
                std::cout << "\t" << stock.Name;
                std::cout << "\t" << stock.OrderQuantity << std::endl;
            }
            std::cout << "\n\n";
        }
    }
    getchar();
}

void SearchOrders() {

    if (customers.empty())
    {
        std::cout << "\n\tNo customers with orders to Search.";
        return;
    }

    std::cout << "\nEnter Customer ID\n";

    std::string customerIDInput;
    getline(std::cin, customerIDInput);

    for (auto const& customer : customers)
    {
        if (customerIDInput == customer.ID)
        {
            for (auto& order : customer.customerOrders) 
            {
                std::cout << "\n" << order.ID << std::endl;

                for (auto& stock : order.OrderStock) 
                {
                    std::cout << "\t" << "\t" << stock.ID;
                    std::cout << "\t" << stock.Name;
                    std::cout << "\t" << stock.OrderQuantity << std::endl;
                }
            }
            return;
        }
    }
    std::cout << "\nNo customer with that ID has been found.";
}

void CancelOrder()
{
    std::cout << "\nEnter the Customer ID for the order to cancel\n";

    std::string CustomerIDInput;
    getline(std::cin, CustomerIDInput);

    for (auto& customer : customers)
    {
        if (customer.ID == CustomerIDInput) 
        {
            int iteration = 1;
            for (auto& order : customer.customerOrders) 
            {
                std::cout << "\n\n" << iteration << " | " << order.ID << std::endl;

                for (auto& stock : order.OrderStock) 
                {
                    std::cout << "\t" << "\t" << stock.ID; 
                    std::cout << "\t" << stock.Name; 
                    std::cout << "\t" << stock.OrderQuantity << std::endl;
                }
                iteration++;
            }

            if (customer.customerOrders.empty()) 
            {
                std::cout << "\nNo orders to cancel for this customer." << std::endl;
                return;
            }

            std::cout << "\nEnter the index of the order to cancel." << std::endl;

            int orderIndexToCancel;
            std::cin >> orderIndexToCancel;

            std::cout << "\nOrder '" << customer.customerOrders[orderIndexToCancel - 1].ID << "' removed.";
            customer.customerOrders.erase(customer.customerOrders.begin() + orderIndexToCancel - 1);

            getchar();
            return;
        }
    }
    std::cout << "\nNo customer with that ID has been found.";
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