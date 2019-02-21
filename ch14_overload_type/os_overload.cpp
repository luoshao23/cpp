#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    friend ostream &operator<<(ostream&, const Person&);
    friend istream &operator>>(istream &, Person &);
    Person(string name, int age) : name(name), age(age) {}

  private:
    string name;
    int age;
};

ostream &operator<<(ostream &os, const Person &p)
{
    os << p.name << " " << p.age;
    return os;
}

istream &operator>>(istream &is, Person &p)
{
    is >> p.name >> p.age;
    if (!is)
        throw runtime_error("Error!");
    return is;
}

int main()
{
    Person me("luo", 28);
    cout << me << endl;
    cin >> me;
    cout << me << endl;
}