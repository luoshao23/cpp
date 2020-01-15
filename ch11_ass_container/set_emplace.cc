#include <set>
using std::set;
#include <iostream>
using std::cout;
#include <typeinfo>

int main()
{
    set<int> iset;
    iset.emplace(5);
    auto res = iset.emplace(5);
    cout << *res.first << " " << res.second << "\n";

    for (auto i : iset)
        cout << i << "\n";

}