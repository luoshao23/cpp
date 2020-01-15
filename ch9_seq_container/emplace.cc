#include <iostream>
#include <vector>
template <class T>
class vect {
public:
	std::vector<T> container;
	template <class... Args>
	void emplace(Args... args){
		container.push_back(T(args...));
//		container.push_back(T(*args...));
	}
};

class Sales {
public:
	int no;
	int num;
	Sales() = default;
	Sales(int n, int m): no(n), num(m) {};
};

int main() {
	vect<Sales> c;
	c.emplace(2, 55);
	for (auto i : c.container)
		std::cout << i.no << " " << i.num;
	return 0;

}
