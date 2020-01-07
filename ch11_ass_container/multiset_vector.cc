#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
void print(const T& t){
    for (auto ti : t)
        cout << ti << " ";
    cout << endl;
}

int main()
{
    vector<string> v = {"hi", "sds", "sd"};
    set<string> c = {"cool", "huya", "lo"};
    print(v);
    print(c);
    copy(v.begin(), v.end(), inserter(c, c.end())); // set not maintain the order, will update the order by comparator
    // copy(c.begin(), c.end(), inserter(v, v.end()));
    // copy(v.begin(), v.end(), back_inserter(c)); // raise error, set doesn't have push_back
    // copy(c.begin(), c.end(), back_inserter(v));
    print(v);
    print(c);
}