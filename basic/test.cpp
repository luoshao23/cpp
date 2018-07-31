#include <iostream>
#include <vector>
using namespace std;

void m2(string& s1, string& s2)
{
    s1 = s1 + "@\n";
    s2 += "@\n";
}

void m3(string& s1, string& s2)
{
    s1 = s1.substr(1, 2);
    s2.replace(0, 5, "\nShellder");
}

int main(){
    vector<int> books = { 1,5,8,2 };

    for (int& b : books)
    {
        cout << b << endl;
    }


    return 0;
}