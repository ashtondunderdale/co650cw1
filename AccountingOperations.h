#pragma once
#pragma once

#include <string>


#ifndef ACCOUNTING_OPERATIONS_H
#define ACCOUNTING_OPERATIONS_H

class AccountingOperations
{
	private:
		static void DisplayAccountingInterface();

		static void ViewAccounts();
		static void AddAccount();

		friend class SalesInterface;
};

#endif 
