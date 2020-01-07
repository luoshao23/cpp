#include <iostream>
#include <string>
#include <initializer_list>

int main(){
	void error_msg(std::initializer_list<std::string> li);
	error_msg({"sds", "dddd", "error"});

	return 0;
}

void error_msg(std::initializer_list<std::string> li){
	for (auto s : li)
		std::cout << s << std::endl;
}
