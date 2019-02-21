#include <iostream>

using namespace std;

class Order
{
public:
    friend ostream& operator<<(ostream &os, const Order &p);
    friend Order operator+(const Order&, const Order&);
    Order(double p, int n): price(p), number(n) {}
private:
    double price;
    int number;
};

Order operator+(const Order &lhs, const Order &rhs)
{
    double price;
    int number;
    number = lhs.number + rhs.number;
    price = (lhs.price * lhs.number + rhs.price * rhs.number) / number;
    return Order(price, number);
}

ostream& operator<<(ostream &os, const Order &p)
{
    os << p.price << " " << p.number;
    return os;
}

int main()
{
    Order l(23.4 , 5);
    Order r(50, 3);
    std::cout << l + r << std::endl;
}
