#include <memory>
using std::make_shared;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    auto pi = make_shared<int>(5);
    auto ps = make_shared<string>(4, 's');
    auto copy_ps(ps);
    *ps = "as";

    cout << pi << " " << ps << " " << copy_ps << endl;
    cout << *pi << " " << *ps << " " << *copy_ps << endl;
}