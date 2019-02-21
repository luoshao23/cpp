#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 10> ia1 = {54, 23};
	array<int, 10> ia2 = ia1;
	array<int, 5> ia3;

	ia1[4] = 23;

	for (auto e: ia1)
		cout << e << endl;

	for (auto e: ia2)
		cout << e << endl;

	// ia3 = ia2; // error

	return 0;
}
