#include <iostream>
#include <ctime>
int main()
{
	std::time_t start = std::time(NULL);
	for (int j = 0; j < 10; ++j){
		long k = 0;
		for (int i = 0; i < 100000000; ++i)
			k += i;
	}
	std::cout << "Wall time passed: "
			  << std::difftime(std::time(NULL), start) / 10.0 << " s. per iteration\n";
}
