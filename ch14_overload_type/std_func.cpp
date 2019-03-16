#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	plus<int> intAdd;
	negate<int> intNeg;

	int sum = intAdd(10, 20);
	cout << sum << endl;
	sum = intNeg(intAdd(20, 10));
	cout << sum << endl;
	sum = intAdd(10, intNeg(10));
	cout << sum << endl;

	vector<string> svec = {"nice", "to", "meet", "you", "again"};
	sort(svec.begin(), svec.end(), less<string>());

	for (auto s : svec)
		cout << s << " ";
	cout << endl;

	return 0;
}
