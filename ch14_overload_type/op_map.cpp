#include <string>
#include <map>
#include <iostream>
#include <functional>


using namespace std;

int add(int a, int b) { return a + b; }

int main()
{
    map<string, int(*)(int, int)> binops;
    function<int(int, int)> f1 = [](int i, int j){ return i * j; };
    map<string, function<int(int, int)>> bop = {
        {"+", add},
        {"-", minus<int>()},
        {"*", f1},
        {"/", [](int i, int j){ return i / j; }}
    };
    binops.insert({"+", add});

    cout << binops["+"](6, 8) << endl;
    cout << f1(6, 8) << endl;
    cout << bop["+"](6, 8) << endl;
    cout << bop["-"](6, 8) << endl;
    cout << bop["*"](6, 8) << endl;
    cout << bop["/"](6, 8) << endl;


}