#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> iv{3, 2, 4};
//	auto it = inserter(iv, iv.end());
//	auto it = back_inserter(iv); 
	auto it = front_inserter(iv); 
	it = 5;

	for (auto i : iv)
		cout << i << ", ";
}

