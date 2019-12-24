#include <iostream>
#include "func.h"

void print(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end)
{
	std::cout << "<";
	for (auto s = beg; s != end; ++s)
	{
		if (s + 1 == end)
			std::cout << *s << ">" << std::endl;
		else
			std::cout << *s << ", ";
	}

}

