#include <set>
using std::multiset;

#include <iostream>
using std::ostream;
using std::cout; using std::endl;

class myClass {
public:
    friend bool isLess(const myClass &a, const myClass &b);
    myClass() = default;
    myClass(int a): age(a) {};
    int getAge() { return age; }
private:
    int age;
};

bool isLess(const myClass &a, const myClass &b)
{
    return a.age < b.age;
}

ostream &operator<<(ostream &os, const multiset<myClass, decltype(isLess) *> &k)
{
    for (auto i: k)
        os << i.getAge() << " ";
    return os;
}

int main()
{
    multiset<myClass, decltype(isLess)*> cool(isLess);
    cool.insert(myClass(3));
    cool.insert(myClass(3));
    cool.insert(myClass(4));

    cout << cool << endl;

}