#include <functional>
#include <map>
#include <iostream>

int add(int i, int j)
{
    return i + j;
}

struct divide
{
    int operator()(int a, int b)
    {
        return a / b;
    }
};

int main(){

    auto mod = [](int i, int j) { return i % j;};

    std::function<int(int, int)> f1 = add;
    std::function<int(int, int)> f2 = divide();
    std::function<int(int, int)> f3 = mod;

    std::cout << f1(5, 2) << std::endl;
    std::cout << f2(5, 2) << std::endl;
    std::cout << f3(5, 2) << std::endl;

    std::map<std::string, std::function<int(int, int) >> binops = {
        {"+", add},
        {"/", divide()},
        {"%", mod},
    };

    std::cout << binops["+"](5, 2) << std::endl;
    std::cout << binops["/"](5, 2) << std::endl;
    std::cout << binops["%"](5, 2) << std::endl;
}