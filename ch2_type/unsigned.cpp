#include <iostream>
using namespace std;

int reused = 42;

int main()
{
	unsigned u = 10;
	unsigned u2 = 42;
	int i = -42;
	cout << i + i << endl;
	cout << u + i << endl;
	cout << 10 << endl;
	cout << 'a'<< endl;
	cout << reused << endl;
	cout << ::reused << endl;
	int reused = 0;
	cout << reused << endl;
	cout << ::reused << endl;

	return 0;
}
