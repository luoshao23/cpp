#include <iostream>
using namespace std;

int main()
{
	int i = -1; 
	int i2 = 3;
	int *const p2 = &i2;
	//p2 = &i;
	const int *p3 = &i;
	*p3  = 4;

	return 0;
}
