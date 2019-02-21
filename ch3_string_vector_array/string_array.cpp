#include <iostream>
using namespace std;

int main()
{
	const char ca[] = {'e', 's', 'l', '\0'};
	const char *cp = ca;
	while(*cp)
	{
		cout << *cp << endl;
		++cp;
	}
	cout << *cp << endl;
	return 0;
}
