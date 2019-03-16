#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t) {
    return os << t << endl;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main(int argc, char const *argv[])
{
    // vector<string> s(argv);
    print(cout, 23, "we");
    return 0;
}


