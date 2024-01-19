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

void AddSampleCustomers();

void CleanConsole();

// Global Variables
std::list<Customer> customers;


int main()
{
    while (true) 
    {
        AddSampleCustomers();
        DisplaySalesInterface();
    }
}

void AddSampleCustomers()
{
    std::vector<std::string> names = { "C++ Industries", "C# Academy", "Python Inc." };
    std::vector<std::string> addresses = { "BB11LOJ", "BB24UJK", "BB09LAY" };
    std::vector<std::string> contacts = { "07929774839", "08172984429", "07839418273" };

    for (size_t i = 0; i < names.size(); ++i) {
        Customer customer;
        customer.ID = GenerateCustomerID();
        customer.Name = names[i];
        customer.DeliveryAddress = addresses[i];
        customer.Contact = contacts[i];
        customer.IsActive = true;

        customers.push_back(customer);
    }
}



void DisplaySalesInterface() 
{
    std::cout << "Main Sales Interface\n\n 1. Customers\n 2. Sales  \n\n";
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
    std::cout << "Customer Interface\n\n 1. Add Customer\n 2. View Customers\n 3. Search Customers \n\n";

    std::string customerNameInput;
    getline(std::cin, customerNameInput);

    if (customerNameInput == "1") 
    {
        AddCustomer();
    }
    else if (customerNameInput == "2") 
    {
        ViewCustomers();
    }
    else if (customerNameInput == "3") 
    {
        SearchCustomers();
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

    Customer customer;
    customer.ID = GenerateCustomerID();
    customer.Name = customerNameInput;

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
        std::cout << "\n" << customer.ID << "\n";
        std::cout << customer.Name << "\n\n";
    }
}


void SearchCustomers() {

    if (customers.empty()) 
    {
        std::cout << "\n\tNo customers to Search.";
        return;
    }

    std::cout << "Enter Customer ID\n";

    std::string customerIDInput;
    getline(std::cin, customerIDInput);

    for (auto const& customer : customers) 
    {
        if (customerIDInput == customer.ID) 
        {
            std::cout << "\nCustomer '" << customerIDInput << "' Found\n\n";
            std::cout << customer.ID << "\n";
            std::cout << customer.Name;
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