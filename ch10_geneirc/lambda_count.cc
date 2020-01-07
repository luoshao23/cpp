#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std::placeholders;

int main() {
	size_t sz = 3;
	std::vector<std::string> sv{"nice", "to", "meet", "you"};
	int num = std::count_if(sv.begin(), sv.end(), 
			[sz](std::string &w) {return w.size() >=  sz;});
	std::cout << num << std::endl;
	auto f = [](std::string &w, int sz) {return w.size() >= sz;};
	auto g = std::bind(f, _1, 2);
	int nums = std::count_if(sv.begin(), sv.end(), g);
	std::cout << nums << std::endl;


	return 0;
}
