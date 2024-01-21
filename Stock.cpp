#include "Stock.h"
#include <string>
#include <list>

Stock::Stock(std::string id, std::string name)
{
	ID = id;
	Name = name;
}

std::list<Stock> stockData = {
    Stock("ID1", "Item1"),
    Stock("ID2", "Item2"),
};