#include <iostream>
using namespace std;

int main()
{
	int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int *p = NULL;

	for (p = &a[0][0]; p < &a[0][0] + 12; p++)
		cout << p << " " << *p << " " << endl;

	return 0;
}
