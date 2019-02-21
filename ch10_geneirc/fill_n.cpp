#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	fill_n(vec.begin(), vec.size(), 1);
	for (auto e: vec)
		cout << e << endl;

	return 0;
}
