#include <iostream>
#include <list>

int main() {
	std::list<int> ilst = {5, 2, 4};
	ilst.insert(std::next(ilst.begin(), 1), 7);

	for (auto i : ilst)
		std::cout << i <<" ";

	return 0;
}
