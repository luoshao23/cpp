#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

// ostream &iprint(ostream& os, vector<int> &tlst) {
// 	for (auto ti : tlst)
// 		os << ti << ", ";
// 	return os;
// }

template <typename T>
ostream &iprint(ostream& os, T &tlst)
{
	for (auto ti : tlst)
		os << ti << ", ";
	return os;
}



int main() {
	vector<int> iv{4, 2, 5, 1};
	auto printso = bind(iprint<vector<int>>, ref(cout), _1);
	// auto printso = bind(iprint<vector<int>>, ref(cout), _1);
	printso(iv);



}
