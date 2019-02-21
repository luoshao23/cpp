#include <iostream>
using namespace std;

void reset(int *ip)
{
	*ip = 3;
	ip = 0;
}

void reset(int &i)
{
	i = 0;
}

int main()
{
	int i = 24;
	reset(&i);
	cout << i << endl;
	reset(i);
	cout << i << endl;

	return 0;

}
