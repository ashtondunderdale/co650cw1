#include "Stock.h"
#include <string>
#include <vector>

Stock::Stock(std::string id, std::string name, int quantity, int orderQuantity)
{
	ID = id;
	Name = name;
	Quantity = quantity;
	OrderQuantity = orderQuantity;
}