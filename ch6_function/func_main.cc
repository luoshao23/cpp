#include <iostream>
#include "func.h"

int main()
{
	void print(std::vector<int>::const_iterator beg, 
		     std::vector<int>::const_iterator end);
	std::vector<int> ivec;
	for (int i = 0; i < 10; ++i)
		ivec.push_back(i);

	print(begin(ivec), end(ivec));

	return 0;
}

