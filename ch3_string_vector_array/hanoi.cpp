#include <iostream>
using namespace std;

void move(int m, char x, char y, char z)
{
	if (m == 1)
		cout << "Move from " << x << " to " << z <<endl;
	else
	{
		move(m - 1, x, z, y);
		cout << "Move from " << x << " to " << z <<endl;
		move(m - 1, y, x, z);
	}
}

int main()
{
	int n;
	cout << "Input number of the plates: ";
	cin >> n;
	cout << "The process to move " << n << " plates between 3 pillars:" << endl;
	move(n, 'A', 'B', 'C');
	return 0;
}
