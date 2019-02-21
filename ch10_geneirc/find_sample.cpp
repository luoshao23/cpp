#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int val = 42;
	vector<int> vec = {1,2,4,78,42};
	auto result = find(vec.cbegin(), vec.cend(), val);
	cout << "The value " << val
		<< (result == vec.cend()
		? " is not present" : " is present") << endl;

	int ia[] = {28, 210, 12, 47};
	int ival = 210;
	int* res = find(begin(ia), end(ia), ival);
	cout << res << " " << *res << endl;
	res = find(ia + 1, ia + 3, 12);
	cout << res << " " << *res << endl;

	cout << accumulate(begin(ia), end(ia), 0) << endl;
	string sv[] = {"nice ", "to ", "meet ", "you"};
	cout << accumulate(begin(sv), end(sv), string("")) << endl;


	return 0;
}
