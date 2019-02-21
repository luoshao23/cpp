#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, string> authors = {{"She", "C++"}, {"Luo", "C++"}, {"Luo", "B++"}, {"Luo", "D++"}};
    string search_item("Luo");

    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);

    cout << "use `find` member function" << endl;
    while(entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }

    cout << "use iterator" << endl;
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item);
    beg != end; ++beg)
        cout << beg->second << endl;

    cout << "use range" << endl;
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;
}