#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.begin(), ivec.end());
    multiset<int> miset(ivec.begin(), ivec.end());

    for (auto a: iset)
        cout << a << ' ';
    cout << endl;

    for (auto ma: miset)
        cout << ma << ' ';
    cout << endl;
}