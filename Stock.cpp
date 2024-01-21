#include "Stock.h"
#include <string>
#include <list>

Stock::Stock(std::string id, std::string name, int quantity, int orderQuantity)
{
	ID = id;
	Name = name;
	Quantity = quantity;
	OrderQuantity = orderQuantity;
}

std::list<Stock> stockData = {
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
    Stock("sdfj23sdfj2sd9s3", "Concrete Mix 50lb", 7, 0),
    Stock("sdfj23sdfj2sdf98", "Saw (Circular)", 9, 0),
    Stock("sdfj23sdfj2sd034", "Measuring Tape 25ft", 20, 0),
    Stock("sdfj23sdfj2sd893", "Safety Gloves", 35, 0),
    Stock("sdfj23sdfj2sdjfl", "Sanding Paper (Fine)", 15, 0),
    Stock("sdfj23sdfj2sdjg2", "Cordless Screwdriver", 6, 0),
    Stock("sdfj23sdfj2sd234h", "Light Bulb (LED)", 30, 0),
    Stock("sdfj23sdfj2sdf78e", "Caulk Gun", 8, 0),
    Stock("sdfj23sdfj2sd0l93", "Plumbing Tape", 25, 0),
};
