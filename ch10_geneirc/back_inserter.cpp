#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	auto it = back_inserter(vec);
	*it = 12;

	for (auto e: it)
		cout << e << endl;

	return 0;
}
