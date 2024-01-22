#pragma once

#include <string>

#include <list>
#include "Customer.h" 

#ifndef CUSTOMER_OPERATIONS_H
#define CUSTOMER_OPERATIONS_H

extern std::list<Customer> customers;

class CustomerOperations 
{
	public:
		static void DisplayCustomerInterface();

		static void AddCustomer();
		static void ViewCustomers();
		static void SearchCustomers();
		static std::string GenerateCustomerID();
		static void ChangeCustomerStatus();

		static void AddSampleCustomers();
};



#endif 
