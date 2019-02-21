#include <iostream>
using namespace std;

int main()
{
	void test(int &a);
	int ival = 42;
	int *p = &ival;

	cout << p << endl;
	cout << *p << endl;

	int *p1 = nullptr;
	int *p2 = 0;
	int aa = 23;
	cout << p1 << p2 << endl;
	test(aa);
	cout << aa << endl;

	return 0;
}

void test(int &a)
{
	cout << a << endl;
	a += 3;
	cout << a << endl;
}
