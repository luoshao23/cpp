#include <iostream>
using namespace std;

int main()
{
	int a[3][4] = {{1,2,3,4},
			   {2,3,4,5},
			   {5,6,7,8}};
	for (int (*p)[4] = a; p != a + 3; p++) {
		for (int *q = *p; q != *p + 4; q++)
			cout << *q << ' ';
		cout << endl;
	}

	for (auto p = a; p != a + 3; ++p){
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	for (auto p = begin(a); p != end(a); ++p){
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	return 0;
}
