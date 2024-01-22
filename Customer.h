#pragma once

#include <string>
#include <list>
#include "Order.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    public:
        static int CustomerCount;
        std::string ID;
        std::string Name;
        std::string DeliveryAddress;
        std::string Contact;
        bool IsActive = true;

        std::vector<Order> CustomerOrders;

        Customer(std::string id, std::string name, std::string deliveryAddress, std::string contact);
};


class TradeCustomer : public Customer
{
    public:
        std::string CompanyName;
        int CreditLimit = 5000;
        std::string SalesRepresentative;

        TradeCustomer(std::string id, std::string name, std::string deliveryAddress, std::string contact,
            std::string businessType, std::string salesRepresentative);
};


class RetailCustomer : public Customer
{
    public:
        int LoyaltyPoints = 0;
        double DiscountRate = 10;

        RetailCustomer(std::string id, std::string name, std::string deliveryAddress, std::string contact);
};

#endif
