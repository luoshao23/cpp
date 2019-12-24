#include <iostream>
using namespace std;

int main() {
	int ival = 23;
	int &refVal = ival;

	cout << ival << " " << refVal << endl;

	ival = 55;
	cout << ival << " " << refVal << endl;

	refVal = 10;
	cout << ival << " " << refVal << endl;

	// int &another = 3; // error

	return 0;
	
}
