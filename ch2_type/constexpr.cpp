#include <iostream>
using namespace std;

int main() {
	constexpr int i = 42;
	void func();
	func();
	return 0;

}
void func() {
	constexpr int i;
	constexpr int *p = &i;
}
