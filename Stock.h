#pragma once

#include <string>
#include <vector>

#ifndef STOCK_H
#define STOCK_H

class Stock
{
	public:
		std::string ID;
		std::string Name;
		int Quantity;
		int OrderQuantity;

		Stock(std::string id, std::string name, int quantity, int orderQuantity);
};

#endif