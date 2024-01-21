#pragma once

#include <string>
#include <list>
#include "Order.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer 
{
    public:
        std::string ID;
        std::string Name;
        std::string DeliveryAddress;
        std::string Contact;
        bool IsActive = true;

        std::vector<Order> CustomerOrders;

        Customer(std::string id, std::string name, std::string deliveryAddress, std::string contact);
};

#endif
