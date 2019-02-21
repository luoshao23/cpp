#include <iostream>
using namespace std;

int main()
{
	int a[10], *p = NULL, *q = NULL, temp;
	for (p = a; p < a + 10; p++)
	{
		cin >> *p;
	}

	for(p = a, q = a + 9; p < q; p++, q--)
	{
		temp = *p; *p = *q; *q = temp;
	}

	for (p = a; p < a + 10; p++)
		cout << *p << " ";

	return 0;
}
