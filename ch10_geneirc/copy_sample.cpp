#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	int a1[] = {0,1,2,3,4,5,6,7,8};
	int a2[sizeof(a1)/sizeof(*a1)];

	auto ret = copy(begin(a1), end(a1), a2);

	cout << ret << endl;
	for (auto e: a2)
		cout << e << endl;

	for (int i = 1; i < 5; ++i)
		cout << *(ret - i) << endl;

	return 0;
}
