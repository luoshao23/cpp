#include <vector>
using std::vector;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::remove_copy_if;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> v1{2, 3, 4, 5, 6};
	vector<int> v2;
	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
			[](int &i){return i % 2 == 0;});

	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	for (auto i : v2)
		cout << i << " ";
	cout << endl;
}

