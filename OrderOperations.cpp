#include <iostream>
#include <list>
#include <random>

#include "OrderOperations.h"
#include "CustomerOperations.h"
#include "Order.h"
#include "Stock.h"
#include "Main.h"



void OrderOperations::DisplayOrderInterface()
{
    std::cout << "Order Management Interface\n\n 1 |  Create New Order\n 2 |  View Existing Orders\n 3 |  Search Order Database\n 4 |  Cancel Pending Order\n\n";

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


    void OrderOperations::AddOrder()
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

                if (!customer.IsActive)
                {
                    std::cout << "\nThis customer is not currently active. Activate this customer to create an order." << std::endl;
                    std::cin.get(); 
                    return;
                }

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

                        if (stockToOrder.size() > 4) 
                        {   
                            std::cout << "\n\nDiscount Applicable for customer" << "\n\nEnter 1 to apply standard discount, or 2 to apply fixed discount of 10." << std::endl;

                            std::string discountInput;
                            std::cin >> discountInput;

                            if (discountInput == "1")
                            {
                                CalculateDiscount(stockToOrder);
                            }
                            else if (discountInput == "2")
                            {
                                CalculateDiscount(10, stockToOrder); 
                            }
                            else 
                            {
                                std::cout << "\nNo discount applied." << std::endl;
                            }
                        }


                        Order order(
                            GenerateOrderID(),
                            stockToOrder
                        );
                       
                        customer.PlaceOrder(order);

                        std::cin.get();
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

                    std::cin.get();
                    std::cin.get();
                }

                std::cout << "\nAdded Order to '" << customer.Name << "'." << std::endl;
                std::cin.get();
                return;
            }
        }
        std::cout << "\nA customer with that ID does not exist." << std::endl;
        std::cin.get();
    }

    void OrderOperations::ViewOrders()
    {
        for (auto& customer : customers)
        {
            std::cout << "\n\n" << customer.Name << std::endl;

            for (auto& customerOrder : customer.CustomerOrders)
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
        std::cin.get();
    }

    void OrderOperations::SearchOrders() {

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
                for (auto& order : customer.CustomerOrders)
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

    void OrderOperations::CancelOrder()
    {
        std::cout << "\nEnter the Customer ID for the order to cancel\n";

        std::string CustomerIDInput;
        getline(std::cin, CustomerIDInput);

        for (auto& customer : customers)
        {
            if (customer.ID == CustomerIDInput)
            {
                int iteration = 1;
                for (auto& order : customer.CustomerOrders)
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

                if (customer.CustomerOrders.empty())
                {
                    std::cout << "\nNo orders to cancel for this customer." << std::endl;
                    return;
                }

                std::cout << "\nEnter the index of the order to cancel." << std::endl;

                int orderIndexToCancel;
                std::cin >> orderIndexToCancel;

                std::cout << "\nOrder '" << customer.CustomerOrders[orderIndexToCancel - 1].ID << "' removed.";
                customer.CustomerOrders.erase(customer.CustomerOrders.begin() + orderIndexToCancel - 1);

                std::cin.get();

                return;
            }
        }
        std::cout << "\nNo customer with that ID has been found.";
    }

    double OrderOperations::CalculateDiscount(std::vector<Stock> stockToOrder)
    {
            const double maxDiscountPercentage = 100.0;

            double discount = static_cast<double>(stockToOrder.size()) * 100.0 / 5.0;
            discount = std::min(discount, maxDiscountPercentage);

            std::cout << "\nApplying discount of $" << discount << ".\n";

            return discount;
    }

    double OrderOperations::CalculateDiscount(double fixedAmount, std::vector<Stock> stockToOrder)
    {
            double discount = fixedAmount;

            double discountedAmount = (stockToOrder.size()) * 10 - discount;

            std::cout << "\nApplying a fixed amount discount of $" << discount << ".\n";
            std::cout << "Order amount after discount: $" << discountedAmount << ".\n";

            return discountedAmount;
    }

    std::string OrderOperations::GenerateOrderID() {
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
