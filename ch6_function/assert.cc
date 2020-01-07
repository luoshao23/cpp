#include <cassert>
#include <iostream>

// g++ assert.cc -D NDEBUG
int main(){
//	assert(1 > 3);
	std::cout << __func__ << std::endl;
	return 0;
}
