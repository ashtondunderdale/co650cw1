#include <iostream>
#include <string>
#include <list>
#include "Customer.h"
#include <vector>

// Method Declarations
void DisplaySalesInterface();
void DisplayCustomerInterface(); 
void DisplayOrderInterface(); 

void AddCustomer();
void ViewCustomers();
void SearchCustomers();
std::string GenerateCustomerID();
void DeactivateCustomer(); 

void AddSampleCustomers();

void CleanConsole();

// Global Variables
std::list<Customer> customers;


int main()
{
    AddSampleCustomers();

    while (true) 
    {
        DisplaySalesInterface();
    }
}


void AddSampleCustomers()
{
    std::vector<std::string> names = { "C++ Industries", "C# Academy", "Python Inc." };
    std::vector<std::string> addresses = { "BB11LOJ", "BB24UJK", "BB09LAY" };
    std::vector<std::string> contacts = { "07929774839", "08172984429", "07839418273" };

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


void DisplayCustomerInterface() 
{
    std::cout << "Customer Interface\n\n 1. Add New Customer\n 2. View Customers\n 3. Search Customers\n 4. Deactivate Customer \n\n";

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
        DeactivateCustomer();
    }
    CleanConsole(); 
}


void DisplayOrderInterface() 
{
    std::cout << "Order Interface\n\n 1. Add Order\n 2. View Orders \n\n";


    CleanConsole(); 
}


void AddCustomer() 
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
    std::cout << "\nAdded Customer '" << customerNameInput << "'"; 
}

void ViewCustomers() 
{

    if (customers.empty()) 
    {
        std::cout << "\n\tNo customers to Display.";
        return;
    }

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
}


void SearchCustomers() {

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


void DeactivateCustomer() 
{
    std::cout << "\nEnter the Customer ID to deactivate\n";

    std::string deactivateCustomerIDInput;
    getline(std::cin, deactivateCustomerIDInput);

    for (auto& customer : customers)
    {
        if (deactivateCustomerIDInput == customer.ID)
        {
            customer.IsActive = false;

            std::cout << "\nDeactivated customer: '" << customer.Name << "'";
            return;
        }
    }
    std::cout << "\nNo customer with that ID has been found.";
}


std::string GenerateCustomerID() 
{
    std::string IDPrefix = "100000";

    int customerListLength = customers.size() + 1;
    std::string customerIDNumber = std::to_string(customerListLength);

    std::string customerID = IDPrefix + customerIDNumber;

    return customerID;
}


void CleanConsole() 
{
    std::cout << "\n\n\tPress Enter to return.";
    getchar();
    system("CLS");
}