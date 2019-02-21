#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Entry {
    string name;
    int number;
};

void print_entry(vector<Entry>& a, int i)
{
    cout << a[i].name <<", "<< a[i].number << endl;
}

int main(){
    vector<Entry> phone_book(1000);
    list<Entry> p(50);

    phone_book[200].name = "we";
    phone_book[200].number = 250;

    print_entry(phone_book, 200);
    return 0;
}
