#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

int main() {
	list<int> ilist{2, 4, 6, 3, 1, 3};
	vector<int> ivec;
	replace_copy(begin(ilist), end(ilist), back_inserter(ivec), 3, 99);


	for (size_t i = 0; i < ivec.size(); ++i) {
		cout << ivec[i] << endl;
	}
}
