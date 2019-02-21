#include <iostream>
using namespace std;

int main()
{
	string sought = "catch", s;
	while (cin >> s && s != sought)
		;
	cout << "found! " << sought << endl;
	return 0;
}
