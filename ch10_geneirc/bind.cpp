#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << endl;
}

int main()
{
    int n = 8;
    auto f1 = bind(f, _2, _1, 999, cref(n), n);
    f1(80, 12);
}