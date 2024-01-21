#pragma once

#include <string>
#include <vector>
#include "Stock.h"

#ifndef ORDER_H
#define ORDER_H

class Order 
{
	public:
		std::string ID;
		std::vector<Stock> OrderStock;

		Order(std::string id, std::vector<Stock> orderStock);
};

#endif