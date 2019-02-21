#include <set>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> sv1 = {"a", "bb", "ccc"};
    vector<string> sv2;
    multiset<string> sms1 = {"a", "bb", "ccc"};
    multiset<string> sms2;
    copy(sv1.begin(), sv1.end(), inserter(sms2, sms2.end()));
    // copy(sv1.begin(), sv1.end(), back_inserter(sms2)); // error! need `push_back` member function
    copy(sms1.begin(), sms1.end(), inserter(sv2, sv2.end()));
    copy(sms1.begin(), sms1.end(), back_inserter(sv2));
    for (auto e: sms2)
        cout << e << ' ';
    cout << endl;

    for (auto ee : sms1)
        cout << ee << ' ';
    cout << endl;
}