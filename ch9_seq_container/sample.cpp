#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	using vint = vector<int>;
	using lint = list<int>;
	vint v1(10, 10);
	vint v2(10, 20);
	v1.swap(v2);
	for (auto vi : v1)
		cout << vi << endl;

	auto b = v1.begin();
	auto e = v1.end();

	vint v3(b+5, e-1);
	cout << "====" << endl;
	for (auto vi : v3)
		cout << vi <<endl;

	lint l1(reinterpret_cast<lint>(v1));
	for (auto li : l1)
		cout << li << endl;
	return 0;
}
