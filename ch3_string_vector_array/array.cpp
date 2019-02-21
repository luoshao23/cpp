#include <iostream>
#include <string>
using namespace std;

int main()
{
	const unsigned sz = 3;
	int a1[sz] = {0, 1, 2};
	int a2[5] = {0, 1, 2};
	string a3[5] = {"hi", "ho"};
	
	for (auto a : a1)
	{
		cout << a << endl;
	}
	return 0;
}
