#include <iostream>
using namespace std;

int place(int m, int n)
{
	/*
	 * m: number of apples
	 * n: number of plates
	 */
	if (m <= 1 || n <= 1) return 1;
	if (m < n)
	{
		return place(m, m);
	}else{
		// condition1: if there is at least one empty plate, then remove the empty one: place(m, n-1)
		// condition2: if there is no empty plate, then remove one apple in every plate: place(m - n, n)
		return place(m, n - 1) + place(m - n, n);
	}
}

int main()
{
	int m, n;
	cout << "number of apple: ";
	cin >> m;
	cout << "number of plate: ";
	cin >> n;
	cout << place(m, n) << endl;

	return 0;
}
