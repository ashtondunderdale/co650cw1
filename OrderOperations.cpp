#include <iostream>
#include <list>

#include "CustomerOperations.h"
#include "Order.h"


std::list<Order> orders;


void DisplayOrderInterface()
{
    std::cout << "Order Interface\n\n 1. Add Order\n 2. View Orders \n\n";


    CleanConsole();
}