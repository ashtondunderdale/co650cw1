#pragma once
#include <string>

class Customer 
{
    public:
        std::string ID;
        std::string Name;
        std::string DeliveryAddress;
        std::string Contact;
        bool IsActive = true;

        Customer(std::string id, std::string name, std::string deliveryAddress, std::string contact);
};

