#include <iostream>
using namespace std;

int main() {
	int i = 42;
	const int &r1 = i;
	const int &r2 = 42;
	const int &r3 = r1 * 2;
//	int &r4 = r1 * 2;
//	int &r5 = 4;

	double dval = 3.14;
	const int &ri = dval;

//	r1 = 54;

	cout << r1 << endl;
	i = 500;
	cout << r1 << endl;
	return 0;
}
