#include <iostream>
/*
 *
 * this is a main function:
 * read two numbers and return their sum
 *
 */

int main()
{
	// input two numbers
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;	// save our inputs
	std::cin >> v1 >> v2;	// read the numbers
	std::cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << std::endl;	// output
	return 0;
}
