#include <iostream>
#include <list>

std::ostream &operator<<(std::ostream &ostr, const std::list<int> &list)
{
	for (auto &i : list) {
		ostr << " " << i;
	}
	return ostr;
}

int main()
{
	std::list<int> v1 = {1, 2, 3, 4, 5};
	std::list<int> v2;

	auto it = v1.begin();
	std::advance(it, 2);
	auto it2 = v2.begin();
	std::advance(it2, 1);
	v2.splice(it2, v1, it, v1.end());

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
}
