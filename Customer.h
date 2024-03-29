#pragma once

#include <string>
#include <vector>
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

        virtual void PlaceOrder(const Order& order);
};


class TradeCustomer : public Customer
{
    public:
        std::string CompanyName;
        int Credit = 5000;
        static const int MaxCreditLimit = 10000;
        std::string SalesRepresentative;

        TradeCustomer(std::string id, std::string name, std::string deliveryAddress, std::string contact,
            std::string businessType, std::string salesRepresentative);

        void PlaceOrder(const Order& order) override;
};


class RetailCustomer : public Customer
{
    public:
        int LoyaltyPoints = 0;
        double DiscountRate = 10;

        RetailCustomer(std::string id, std::string name, std::string deliveryAddress, std::string contact);

        void PlaceOrder(const Order& order) override;
};

#endif
