#include <iostream>
using namespace std;

template <class T = int> class Numbers {
public:
    // friend ostream &operator<<(ostream &os, const Numbers<T> &t);
  friend ostream &operator<<(ostream &os, const Numbers<T> &t) { return os << t.val; }
    Numbers(T v = 0) : val(v) {}
private:
    T val;
};

// template <class T = int>
// ostream& operator<<(ostream &os, const Numbers<T> &t)
// {
//     return os << t.val;
// }

int main()
{
    Numbers<long double> lots_of_precsion = 3.2;
    Numbers<> my_int;
    cout << lots_of_precsion << endl;
    cout << my_int << endl;
}