#include <iostream>
#include <string>
#include "Sales_data.h"

int main(){
	Sales_data d1, d2;
	double price = 0;
	std::cin >> d1.bookNo >> d1.units_sold >> price;
	d1.revenue = d1.units_sold * price;
	std::cin >> d2.bookNo >> d2.units_sold >> price;
	d2.revenue = d2.units_sold * price;
	if (d1.bookNo == d2.bookNo) {
		unsigned totalCnt = d1.units_sold + d2.units_sold;
		double totalRevenue = d1.revenue + d2.revenue;
		std::cout << d1.bookNo << " " << totalCnt
			<< " " << totalRevenue << " ";
	}

	return 0;
}
