#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
    // if (v1 < v2) return -1;
    // if (v2 < v1) return 1;
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v1)) return 1;
    return 0;
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,3};
    cout << compare(1, 0) << endl;
    cout << compare(1.5, 2.3) << endl;
    cout << compare(v1, v2) << endl;
    cout << compare("hi", "comppppp") << endl;
    return 0;
}