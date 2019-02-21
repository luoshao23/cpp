#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> a1 = {0,1,2,3,4,5,6,7,8};
	vector<int> vec;

	replace_copy(a1.cbegin(), a1.cend(), back_inserter(vec), 0, 999);

	for (auto e: vec)
		cout << e << endl;

	for (auto e: a1)
		cout << e << endl;

	return 0;
}
