#include <iostream>
#include <vector>
using namespace std;



int main() {
    // vector<int> vec = {1, 1, 3, 2, 4, 4, 2, 5};
    vector<int> vec = {1, 1, 3, 2, 4, 4, 2, 5};
    int sum = 0;
    for (int j = 0; j < vec.size(); ++j) {
        sum = sum ^ vec[j];
    }

    cout << sum << endl;
    if (~4)
        cout << "hi" << endl;

    int k = 0;
    int piv = 1;
    while ((piv & sum) == 0) {
        piv <<= 1;
        ++k;
    }
    cout << "k" << k << endl;

    int sum1 = 0;
    sum = 0;
    for (auto a: vec) {
        if ((a & (1 << k)) == 0)
            sum ^= a;
        else
            sum1 ^= a;
    }
    cout << sum << " " << sum1 << endl;

}