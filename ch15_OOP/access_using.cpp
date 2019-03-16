#include <string>
#include <iostream>

class Base {
public:
    std::size_t size() const { return n; }
    std::size_t size_plus() { return n + 1; }
// protected:
    std::size_t n;
};

class Derived : public Base
{
public:
    using Base::size;
    std::size_t size_plus() { return n + 2; }
// protected:
//     using Base::n;
};

int main()
{
    Derived d;
    d.n = 3;
    std::cout << d.Base::size_plus() << " Base" << std::endl;
    std::cout << d.size_plus() << " Derived";
}
