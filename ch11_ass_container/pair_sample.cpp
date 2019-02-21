#include <utility>
#include <vector>
#include <iostream>

using namespace std;

pair<string, int> process(vector<string> &v)
{
    if (!v.empty())
        return {v.back(), v.back().size()};
    else
        return pair<string, int>();
}

int main()
{
    vector<string> sv = {"a", "bc", "def", "ghij"};
    auto res = process(sv);
    cout << res.first << ' ' << res.second << endl;
}
