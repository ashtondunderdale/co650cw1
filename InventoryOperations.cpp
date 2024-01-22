#include <iostream>
#include <string>
#include <iomanip>

#include "InventoryOperations.h"
#include <vector>
#include "Stock.h"
#include "Main.h"

std::vector<Stock> stockData = 
{
    Stock("lkJj8dIse239Dia3", "Metal Pipe 0.2x5m", 20, 0),
    Stock("k928sSla002dDjaf", "Bolt 12mm", 13, 0),
    Stock("sdf8sdn8sdf9sdf9", "Wooden Plank 2x4", 30, 0),
    Stock("p9dj4js89djf3hj2", "Screwdriver", 15, 0),
    Stock("dkfj4j2dfjg2jh34", "Paint Can (Red)", 8, 0),
    Stock("jf9skd038jsl3kdf", "Wrench 10mm", 10, 0),
    Stock("fj23lsd92jd9sld2", "Hammer", 18, 0),
    Stock("sdfj82lsdf9jsdl3", "Plywood Sheet 4x8", 25, 0),
    Stock("d9s8fj23sdfjlsd9", "Nails 2-inch", 100, 0),
    Stock("sd9fj23sdfj2sd38", "Angle Grinder", 5, 0),
    Stock("d9sjf23sdfjlsd23", "Power Drill", 12, 0),
    Stock("KMogGRlpH5wVFjAc", "Concrete Mix 50lb", 7, 0),
    Stock("oJnPhN8FiuOe7Bsq", "Saw (Circular)", 9, 0),
    Stock("rrqnpfgXu73lIciP", "Measuring Tape 25ft", 20, 0),
    Stock("PO1rUVsGa6BJb1lZ", "Safety Gloves", 35, 0),
    Stock("NqInRc6OtKAayUoN", "Sanding Paper (Fine)", 15, 0),
    Stock("GKsUsbh8nLCtA1bs", "Cordless Screwdriver", 6, 0),
    Stock("psDej5SFz4i6mp0D", "Light Bulb (LED)", 30, 0),
    Stock("nl8GM3zVowYKIXyP", "Caulk Gun", 8, 0),
    Stock("5yEoLYzlYbCUUEQS", "Plumbing Tape", 25, 0),
};


void DisplayInventoryInterface()
{
    std::cout << "Inventory Interface\n\n 1 |  Display Stock Levels\n\n";
    std::string inventoryInterfaceInput;

    getline(std::cin, inventoryInterfaceInput);
    system("CLS");

    if (inventoryInterfaceInput == "1")
    {
        DisplayStockLevels();
    }
}

void DisplayStockLevels()
{
    std::cout << std::setw(15) << "ID" << std::setw(25) << "Name" << std::setw(15) << "Quantity" << "\n";
    std::cout << std::setfill('-') << std::setw(55) << "" << std::setfill(' ') << "\n";

    for (auto& stock : stockData)
    {
        std::cout << std::setw(15) << stock.ID;
        std::cout << std::setw(25) << stock.Name;
        std::cout << std::setw(15) << stock.Quantity << "\n";
    }

    CleanConsole();
}