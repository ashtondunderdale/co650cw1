#include <iostream>
#include <string>

#include "Main.h"
#include "AccountingOperations.h"
#include <list>
#include "Account.h"
#include <iomanip>


std::list<Account*> accounts;

void AccountingOperations::DisplayAccountingInterface()
{
    std::cout << "Accounts Interface\n\n 1 |  Add New Account\n 2 |  View Accounts\n\n";

    std::string customerInterfaceInput;
    getline(std::cin, customerInterfaceInput);

    if (customerInterfaceInput == "1")
    {
        AddAccount();
    }
    else if (customerInterfaceInput == "2")
    {
        ViewAccounts();
    }
    CleanConsole();
}

void AccountingOperations::AddAccount()
{
    std::cout << "Enter Debit value" << std::endl;
    double debitValue;
    std::cin >> debitValue;

    std::cout << "Enter Credit value" << std::endl;
    double creditValue;
    std::cin >> creditValue;

    Account* accountPtr = new Account(debitValue, creditValue);

    accounts.push_back(accountPtr);

    std::cout << "\n\nAdded account.";
    std::cin.get();
}

void AccountingOperations::ViewAccounts()
{
    for (auto& account : accounts) 
    {
        std::cout << "Debit: ";
        std::cout << account->Debit;

        std::cout << "\tCredit: ";
        std::cout << account->Credit << std::endl;
    }
}
