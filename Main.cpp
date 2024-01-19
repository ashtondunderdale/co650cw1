#include <iostream>
#include <string>
#include <list>
#include "Customer.h"

// Method Declarations
void DisplaySalesInterface();
void DisplayCustomerInterface(); 
void DisplayOrderInterface(); 

void AddCustomer();
void ViewCustomers();

void CleanConsole();

// Global Variables
std::list<Customer> customers;


int main()
{
    while (true) {
        DisplaySalesInterface();
    }
}

void DisplaySalesInterface() {
    std::cout << "Main Sales Interface\n\n 1. Customers\n 2. Sales  \n\n";
    std::string interfaceInput;

    getline(std::cin, interfaceInput);
    system("CLS");

    if (interfaceInput == "1") {
        DisplayCustomerInterface();
    }
    else if (interfaceInput == "2") {
        DisplayOrderInterface();
    }

}


void DisplayCustomerInterface() {
    std::cout << "Customer Interface\n\n 1. Add Customer\n 2. View Customers \n\n";

    std::string customerNameInput;
    getline(std::cin, customerNameInput);

    if (customerNameInput == "1") {
        AddCustomer();
    }
    else if (customerNameInput == "2") {
        ViewCustomers();
    }

    CleanConsole(); 
}


void DisplayOrderInterface() {
    std::cout << "Order Interface\n\n 1. Add Order\n 2. View Orders \n\n";


    CleanConsole(); 
}


void AddCustomer() {

    std::cout << "\nEnter customer Name\n";

    std::string customerNameInput;
    getline(std::cin, customerNameInput);

    if (customerNameInput.empty()) {
        std::cout << "Customer name cannot be empty";
        return;
    }

    Customer customer;
    customer.ID = "TESTID";
    customer.Name = customerNameInput;

    customers.push_back(customer); 
    std::cout << "\nAdded Customer '" << customerNameInput << "'"; 
}

void ViewCustomers() {
    system("CLS");

    if (customers.empty()) {
        std::cout << "\n\tNo customers to Display";
        return;
    }

    for (auto const& customer : customers) {
        std::cout << customer.Name;
    }
}




void CleanConsole() {
    std::cout << "\n\n\tPress Enter to return.";
    getchar();
    system("CLS");
}