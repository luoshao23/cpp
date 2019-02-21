#include "fact.h"

int fact(int n)
{
	int res = 1;
	for (int i = n; i > 0; --i)
		res *= i;
	return res;
}
