#include <iostream>
using namespace std;

using arrT = int[10];

int main()
{
	auto func(int) -> int(*)[10];
	arrT *d;
	d = func(5);
	cout << d << endl;
	cout << *d << endl;
	cout << **d << endl;
	return 0;
}

arrT* func(int i)
{
	int a[10] = {1};
	int (*p)[10] = &a;
	return p;
}
