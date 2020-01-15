#include <set>
#include <algorithm>
#include <iostream>

int main(){
    std::set<int> a = {4, 2, 6};
    auto g = std::move(a);

    for (auto gi : g)
        std::cout << gi;

    for (auto ai : a)
        std::cout << ai;
}