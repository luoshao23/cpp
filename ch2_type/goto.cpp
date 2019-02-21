#include <iostream>
using namespace std;

int main()
{
	int i = 0, sum = 0;
	i = 1;

loop:
	sum += i;
	i++;
	if (i > 10) goto out;
	goto loop;
out:
	cout << sum << endl;
	return 0;
}
