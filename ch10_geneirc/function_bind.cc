#include <functional>
#include <iostream>
#include <vector>
#include <string>


template<typename T>
std::function<void()> makePrintRangeFunction(void (*f)(T), T param) {
    return std::bind(f, param);
}

template <typename Container>
void printj(Container c)
{
    for (auto ci : c)
        std::cout << ci << '\n';
}

// void printj(std::vector<int> c)
// {
//     for (auto ci : c)
//         std::cout << ci << '\n';
// }

int main()
{
    std::vector<int> iv{1, 4, 2, 8, 5, 7};
    std::vector<std::string> sv{"nice", "to", "meet", "you"};
    auto f = makePrintRangeFunction(printj, iv);
    auto g = makePrintRangeFunction(printj, sv);
    f();
    g();
}