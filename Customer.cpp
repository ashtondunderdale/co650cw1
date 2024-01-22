#include "Customer.h"

int Customer::CustomerCount = 0;

Customer::Customer(std::string id, std::string name, std::string deliveryAddress, std::string contact)
{
	ID = id;
	Name = name;
	DeliveryAddress = deliveryAddress;
	Contact = contact;
}
