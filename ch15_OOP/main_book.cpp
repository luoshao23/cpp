#include <iostream>
#include "book.hpp"
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

double BulkQuote::net_price(size_t n) const {
    if (n > quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}

void Quote::debug() {
    cout << id << " " << price << " ";
}

void BulkQuote::debug() {
    Quote::debug();
    cout << quantity << " " << discount << " ";
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.begin();
              iter != items.end();
              iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
              }
    os << "Total Sale: " << sum << endl;
    return sum;
}

int main()
{
    Quote q("nice", 25.0);
    print_total(cout, q, 2);
    BulkQuote bk("ahdis", 23.4, 3, 0.2);
    double z = print_total(cout, bk, 4);
    q.debug();
    cout << endl;
    bk.debug();
    cout << endl;
    Basket bsk;
    bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(make_shared<BulkQuote>("345", 45, 3, .15));
    bsk.add_item(make_shared<BulkQuote>("345", 45, 3, .15));
    bsk.add_item(make_shared<BulkQuote>("345", 45, 3, .15));
    bsk.add_item(make_shared<BulkQuote>("345", 45, 3, .15));
    bsk.total_receipt(cout);

    return 0;
}