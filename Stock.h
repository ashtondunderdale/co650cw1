#pragma once

#include <string>

#ifndef STOCK_H
#define STOCK_H

class Stock
{
	public:
		std::string ID;
		std::string Name;

		Stock(std::string id, std::string name);
};

#endif