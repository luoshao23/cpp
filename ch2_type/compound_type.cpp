#include <iostream>
using namespace std;

int main()
{
	int ival = 1024;
	int &refVal = ival;
	//int &refVal2; // raise Error, should be initialized

	cout << refVal << endl;

	int ii = refVal;

	cout << ii << endl;

//	int* &refVal3 = &ival; // cannot be the reference of the reference
//	cout << refVal3 << endl;

//	int &refVal4 = 10; // cannot be the reference of a constant
	double dval = 1.23;
//	int &refVal5 = dval; // int double, type not match
	
	int i, &ri = i;
	i = 5; ri = 10;
	cout << i << " " << ri << endl;

	return 0;
}
