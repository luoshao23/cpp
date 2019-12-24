#include <iostream>
#include <string>

int main(){
	std::string line;
	while (getline(std::cin, line))
		if (!line.empty())
			std::cout << line << std::endl;
	return 0;
}
