#include <iostream>

int main()
{	
	int i = 1;
	double d = 2.8;
	i *= d;

	std::cout << i << std::endl;
	i = (double) i * d;
	std::cout << i << std::endl;

	return 0;

}
