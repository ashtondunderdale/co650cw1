#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "CustomerOperations.h"
#include "Customer.h"
#include "Main.h"
#include <iomanip>

std::list<Customer> customers;

void CustomerOperations::DisplayCustomerInterface()
{
    std::cout << "Client Management Interface\n\n 1 |  Add New Customer\n 2 |  View Customer Database\n 3 |  Search Customer Information\n 4 |  Change Customer Profile Status\n\n";

    std::string customerInterfaceInput;
    getline(std::cin, customerInterfaceInput);

    if (customerInterfaceInput == "1")
    {
        AddCustomer();
    }
    else if (customerInterfaceInput == "2")
    {
        ViewCustomers();
    }
    else if (customerInterfaceInput == "3")
    {
        SearchCustomers();
    }
    else if (customerInterfaceInput == "4")
    {
        ChangeCustomerStatus();
    }
    CleanConsole(); 
}


void CustomerOperations::AddCustomer() 
{

    std::cout << "\nEnter customer Name\n";

    std::string customerNameInput;
    getline(std::cin, customerNameInput);

    if (customerNameInput.empty()) 
    {
        std::cout << "Customer name cannot be empty.";
        return;
    }

    std::cout << "\nEnter customer Delivery Address\n";

    std::string customerDeliveryAddressInput;
    getline(std::cin, customerDeliveryAddressInput);

    std::cout << "\nEnter customer Contact\n";

    std::string customerContactInput;
    getline(std::cin, customerContactInput);

    Customer customer(
        GenerateCustomerID(),
        customerNameInput,
        customerDeliveryAddressInput,
        customerContactInput
    );

    customers.push_back(customer); 
    customer.CustomerCount++;
    std::cout << "\nAdded Customer '" << customerNameInput << "'"; 
}

void CustomerOperations::ViewCustomers()
{
    if (customers.empty())
    {
        std::cout << "\n\tNo customers to display.";
        return;
    }

    const int idWidth = 10;
    const int nameWidth = 20;
    const int addressWidth = 30;
    const int contactWidth = 15;
    const int statusWidth = 10;

    std::cout << std::setw(idWidth) << "ID"
        << std::setw(nameWidth) << "NAME"
        << std::setw(addressWidth) << "ADDRESS"
        << std::setw(contactWidth) << "CONTACT"
        << std::setw(statusWidth) << "STATUS" << "\n";
    std::cout << std::setfill('-') << std::setw(idWidth + nameWidth + addressWidth + contactWidth + statusWidth) << "" << std::setfill(' ') << "\n";

    for (const auto& customer : customers)
    {
        std::string IsActiveString = customer.IsActive ? "Active" : "Inactive";

        std::cout << std::setw(idWidth) << customer.ID
            << std::setw(nameWidth) << customer.Name
            << std::setw(addressWidth) << customer.DeliveryAddress
            << std::setw(contactWidth) << customer.Contact
            << std::setw(statusWidth) << IsActiveString << "\n";
    }
}


void CustomerOperations::SearchCustomers() {

    if (customers.empty()) 
    {
        std::cout << "\n\tNo customers to Search.";
        return;
    }

    std::cout << "\nEnter Customer ID\n";

    std::string customerIDInput;
    getline(std::cin, customerIDInput);

    for (auto const& customer : customers) 
    {
        if (customerIDInput == customer.ID) 
        {
            std::string IsActiveString = "Inactive";

            if (customer.IsActive)
            {
                IsActiveString = "Active";
            }

            std::cout << "\nCustomer '" << customer.Name << "' Found\n\n";
            std::cout << "\n" << customer.ID << "\n";
            std::cout << customer.Name << "\n";
            std::cout << customer.DeliveryAddress << "\n";
            std::cout << customer.Contact << "\n";
            std::cout << IsActiveString << "\n";
            return;
        }
    }
    std::cout << "\nNo customer with that ID has been found.";
}


void CustomerOperations::ChangeCustomerStatus()
{
    std::cout << "\nEnter the Customer ID to activate / deactivate\n";

    std::string changeStatusCustomerIDInput;
    getline(std::cin, changeStatusCustomerIDInput);

    for (auto& customer : customers)
    {
        if (changeStatusCustomerIDInput == customer.ID)
        {
            customer.IsActive = !customer.IsActive;

            if (customer.IsActive == true)
            {
                std::cout << "\nActivated customer: '" << customer.Name << "'";
            }
            else 
            {
                std::cout << "\nDeactivated customer: '" << customer.Name << "'";
            }
            return;
        }
    }
    std::cout << "\nNo customer with that ID has been found.";
}


std::string CustomerOperations::GenerateCustomerID()
{
    std::string IDPrefix = "100000";

    int customerListLength = customers.size() + 1;
    std::string customerIDNumber = std::to_string(customerListLength);

    std::string customerID = IDPrefix + customerIDNumber;

    return customerID;
}


void CustomerOperations::AddSampleCustomers()
{
    std::vector<std::string> names = { "C++ Industries", "C# Academy", "Python Inc.", 
                                       "Java Enterprises", "Ruby Innovations", "JS Solutions",
                                       "Swift Systems", "Go Tech Corp", "Rust Innovate" };

    std::vector<std::string> addresses = { "BB11LOJ", "BB24UJK", "BB09LAY", 
                                           "BB18OPQ", "BB23XYZ", "BB05ABC",
                                           "BB15LMN", "BB07DEF", "BB02GHI" };

    std::vector<std::string> contacts = { "07929774839", "08172984429", "07839418273",
                                          "07654321098", "07891234567", "07654321098",
                                          "07567890123", "07456789012", "07345678901" };

    for (size_t i = 0; i < names.size(); ++i) {
        Customer customer(
            GenerateCustomerID(),
            names[i],
            addresses[i],
            contacts[i]
        );

        customers.push_back(customer);
    }
}