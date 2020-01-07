#include <iostream>
#include <algorithm>

int main() {
	int a[] = {2, -4, -2, 0, 1};

	std::transform(std::begin(a), std::end(a), std::begin(a), 
			[](int i) -> int { if (i < 0) return -i; else return i;});

	for (auto ai : a)
		std::cout << ai << ",";

	return 0;
}
