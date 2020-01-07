#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
	int a[8] = {1, 4, 2, 8, 5, 7, 3, 0};

	auto res = std::find(std::begin(a), std::end(a), 7);
	std::cout << *res << std::endl;

	int sum = 0;
	sum = std::accumulate(std::begin(a), std::end(a), 0);
	std::cout << sum ;

	return 0;

}
