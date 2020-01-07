#include <map>
using std::map;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    map<int, int> k = {{1, 2}, {2, 5}, {7, 1}};
    for (auto& ki : k){
        cout << ki.first << " " << ++ki.second << "\n";
    }
}