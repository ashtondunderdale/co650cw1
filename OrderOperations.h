#pragma once

#include <string>
#include "Stock.h"

#ifndef ORDER_OPERATIONS_H
#define ORDER_OPERATIONS_H

extern std::list<Stock> stockData; 

void AddOrder();
void ViewOrders();
void SearchOrders();
void CancelOrder();

std::string GenerateOrderID();

#endif