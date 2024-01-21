#pragma once
#include <string>

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