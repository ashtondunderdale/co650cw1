#pragma once

#include <string>

#include "Stock.h"

#ifndef ORDER_OPERATIONS_H
#define ORDER_OPERATIONS_H

extern std::vector<Stock> stockData; 

class OrderOperations {

    private:
        static void AddOrder();
        static void ViewOrders();
        static void SearchOrders();
        static void CancelOrder();

        static void CalculateDiscount();
        static std::string GenerateOrderID();

        static void DisplayOrderInterface();

    friend class SalesInterface;
};

#endif