#pragma once

#include <string>

#include <list>
#include "Customer.h" 

#ifndef CUSTOMER_OPERATIONS_H
#define CUSTOMER_OPERATIONS_H

extern std::list<Customer> customers;

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

#endif 
