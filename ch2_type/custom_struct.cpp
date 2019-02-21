#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;


int main()
{

	Sales_data sale1, sale2;
	double price;
	cin >> sale1.bookNo >> sale1.units_sold >> price;
	sale1.revenue = sale1.units_sold * price;
	cout << sale1.revenue << endl;

	return 0;
}
