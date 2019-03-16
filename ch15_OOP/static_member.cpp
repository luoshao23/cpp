#include <iostream>

using namespace std;

class Base {
public:
    static int num;
};

class Derived : public Base {

};

class PriDerived : private Base {

};

int Base::num = 3;

int main()
{
    Base b;
    Derived d;
    PriDerived pd;

    cout << b.num << endl;
    d.num = 4;
    cout << b.num << endl;
    // cout << pd.num << endl;

    return 0;
}