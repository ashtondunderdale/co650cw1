#pragma once


#ifndef INVENTORY_OPERATIONS_H
#define INVENTORY_OPERATIONS_H 

class InventoryOperations 
{
	private:
		static void DisplayInventoryInterface();

		static void DisplayStockLevels();

	friend class SalesInterface;
};

#endif