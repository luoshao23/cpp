#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s1("hi!"), s2;
    s2 = move(string("bye!"));
    cout << s2 << endl;
    s2 = move(s1);
    cout << s2 << endl;
    cout << s1 << endl;
}