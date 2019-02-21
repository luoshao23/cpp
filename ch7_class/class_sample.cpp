#include <iostream>
#include "class_sample.h"
using namespace std;

Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}


Sales_data& Sales_data::combine(const Sales_data &other)
{
	units_sold += other.units_sold;
	revenue += other.revenue;
	return *this;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

int main()
{
	Sales_data total, trans;
	trans = Sales_data(cin);
	total.combine(trans);
	cout << total.isbn() << endl;
	read(cin, trans);
	total.combine(trans);
	print(cout, total);
	return 0;
}
