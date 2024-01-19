#pragma once
#include <string>

class Customer 
{
    public:
        std::string ID;
        std::string Name;
        std::string DeliveryAddress;
        std::string Contact;
        bool IsActive;

        std::string ReturnCustomerID();
};

