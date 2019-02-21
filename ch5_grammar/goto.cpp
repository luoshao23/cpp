#include <iostream>
using namespace std;

int main()
{
	goto next;
	cout << "never happen" << endl;
next: 
	cout << "this happened" << endl;
	return 0;
}
