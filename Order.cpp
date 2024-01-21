#include "Order.h"
#include "Stock.h"

Order::Order(std::string id, std::vector<Stock> orderStock)
{
	ID = id;
	OrderStock = orderStock;
}