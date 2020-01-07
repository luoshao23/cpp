#include <map>
using std::map;
#include <string>
using std::string;
#include <utility>
using std::make_pair; using std::pair;
#include <iostream>
using std::cout;

template <class T>
void print(const T& t){
    for (auto ti : t)
        cout << ti.first << " " << ti.second << "\n";
}

int main()
{
    map<string, int> cool;
    cool.insert({"nice", 2});
    cool.insert(make_pair("second", 4));
    cool.insert(pair<string, int>("third", 6));
    print(cool);
}