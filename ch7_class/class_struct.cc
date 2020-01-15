#include "class_struct.h"
#include <iostream>

Sales_data::Sales_data(std::istream &is){
//	Sales_data tmp;
//	read(is, tmp);
//	return tmp;
	read(is, *this);
}

Sales_data add(const Sales_data& s1, const Sales_data &s2){
	Sales_data sum = s1;
	sum.combine(s2);
	return sum;
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
} 

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

std::ostream &print(std::ostream &os, const Sales_data &s){
	os << s.isbn() << " " << s.units_sold << " "
	   << s.revenue << " " << s.avg_price();
	return os;
}

std::istream &read(std::istream &is, Sales_data &s){
	double price = 0;
	is >> s.bookNo >> s.units_sold >> price;
	s.revenue = price * s.units_sold;
	return is;
}
