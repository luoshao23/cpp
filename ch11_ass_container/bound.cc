#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    set<string> dataset = {"hicw", "nice", "as"};
    for (auto begin = dataset.lower_bound("nice"), end = dataset.upper_bound("nice");
        begin != end; ++begin)
        cout << *begin << endl;
}