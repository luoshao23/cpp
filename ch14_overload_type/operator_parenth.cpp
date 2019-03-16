#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct absInt {
    // int operator()(int val) const {
    //     cout << (val < 0 ? -val : val) << endl;
    //     return val < 0 ? -val : val;
    // }
    void operator()(int &val) {
        val = val < 0 ? -val : val;
    }
};

class PrintString {
public:
    PrintString(ostream &o=cout, char c=' '):
        os(o), sep(c) { }
    void operator()(const string &s) const { os << s << sep; }
private:
    ostream &os;
    char sep;
};

int main()
{
    int i = -42;
    int j = 55;
    std::cout << i << " " << j << std::endl;

    absInt absObj;
    // int ui = absObj(i);
    // int uj = absObj(j);
    // std::cout << ui << " " << uj << std::endl;

    PrintString pp(cerr, '-');
    vector<string> svec = {"5", "wow", "強い", "可以"};
    vector<int> ivec = {5, -23, 0, 5, -9};
    for_each(svec.begin(), svec.end(), pp);
    for_each(ivec.begin(), ivec.end(), absObj);
    for (auto v : ivec)
        cout << v << endl;

}