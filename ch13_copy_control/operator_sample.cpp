#include<iostream>
using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(const int &a, const int &b): age(a), mile(b) {}
    Foo(const Foo &o): age(o.age), mile(o.mile) {}
    Foo& operator=(const Foo&);
    // Foo& operator=(const Foo&) = delete;
    string info();
    ~Foo()=default;
private:
    int age;
    int mile;
};

Foo& Foo::operator=(const Foo& other)
{
    cout << "operator = " << endl;
    age = other.age + 23;
    mile = 0;
    return *this;
}

string Foo::info()
{
    return "Age: " + to_string(age) + ", Mile: " + to_string(mile);
}

int main()
{
    int a = 5, b = 3;
    // Foo foo(5, 3);
    Foo foo(a, b);
    Foo k;
    k = foo;
    cout << k.info() << endl;
}
