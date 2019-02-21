#include <iostream>
using namespace std;

int main()
{
	int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int (*p)[3] = NULL, i, j;
	p = a;


	cin >> i >> j;
	cout << *(*(p + i) + j);
	return 0;
}
