#include <iostream>
using namespace std;

int main() {
	int val = 1024;
	int *p1 = &val;
	//int *pp1 = &p1;
	int **pp2 = &p1;

	cout << val << "\n"
		<< p1 << "\n"
		<< *p1 << "\n"
		<< *pp2 << "\n"
		<< **pp2 << "\n";

	return 0;
}
