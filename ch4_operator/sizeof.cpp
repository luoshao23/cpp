#include <iostream>
using namespace std;

int main(){
	int a[] = {2, 3, 4, 5};
	auto sz = sizeof(a) / sizeof(int);
	cout << sizeof(a) << " " << sizeof(int) << endl;
	cout << sz << endl;

	int x[10]; int *p = x;
	cout << sizeof(x)/sizeof(*x) << endl;
	cout << sizeof(x) << " " << sizeof(*x) << endl;
	cout << sizeof(p) << " " << sizeof(*p) << endl;
	return 0;
}
