#include <memory>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(int a, int b): data(a, b){ cout << "Hi!" << endl;}
    ~Foo(){ cout << "Bye!" << endl; }
private:
    pair<int, int> data;
};

shared_ptr<Foo> factory(int a, int b){
    return make_shared<Foo>(a, b);
}

shared_ptr<Foo> factory(){
    return make_shared<Foo>();
}

shared_ptr<Foo> use_factory(int a, int b)
{
    auto p = factory(a, b);
    return p;
}

int main()
{
    auto k = use_factory(2, 5);
    cout << "Doing something" << endl;
}