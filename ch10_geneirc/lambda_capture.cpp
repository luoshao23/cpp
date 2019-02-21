#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    size_t v1 = 42;
    auto f = [v1]{ return v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl;

    v1 = 42;
    auto f2 = [&v1]{ return v1; };
    v1 = 0;
    j = f2();
    cout << j << endl;
}