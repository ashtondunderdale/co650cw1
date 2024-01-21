#pragma once

#include <string>
#include <list>
#include "Order.h"

class Customer 
{
    public:
        std::string ID;
        std::string Name;
        std::string DeliveryAddress;
        std::string Contact;
        bool IsActive = true;

        std::list<Order> customerOrders;

        Customer(std::string id, std::string name, std::string deliveryAddress, std::string contact);
};

