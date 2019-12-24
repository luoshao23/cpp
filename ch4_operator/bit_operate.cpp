#include <iostream>
using namespace std;

int main(){
	unsigned char b1 = 0145;
	unsigned char b2 = 0257;

	cout << b1 << " " << b2 << endl;
	cout << (b1 & b2) << endl;
	cout << (b1 | b2) << endl;
	cout << 0b234 << endl;
	return 0;

}
