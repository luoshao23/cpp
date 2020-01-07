#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> vec;
	auto it = back_inserter(vec);
	*it = 12;
	*it = 33;
	//cout << *it << endl;

	std::fill_n(it, 5, 22);
	for (auto e: vec)
		cout << e << endl;

	return 0;
}
