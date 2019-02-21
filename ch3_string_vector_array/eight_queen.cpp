#include <iostream>
using namespace std;

int a[8]= {0};

int queen(int n)
{
	int check_table(int, int);
	if (n == 8)
	{
		for (int p : a)
			cout << p;
		cout << endl;
		return 1;
	}

	int res = 0;
	for (int i = 1; i <= 8; i++)
	{
		a[n] = i;
		if (check_table(i, n))
			res += queen(n + 1);
		a[n] = 0;
	}
	return res;
}

int check_table(int pos, int j)
{
	int s;
	for (s = j - 1; s >=0; s--)
	{
		if (a[s] == pos)
			return 0;
		if (a[s] == pos + s - j)
			return 0;
		if (a[s] == pos + j - s)
			return 0;
	}
	return 1;
}

int main()
{
	cout << queen(0) << endl;
	return 0;
}
