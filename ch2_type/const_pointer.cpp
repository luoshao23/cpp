#include <iostream>
using namespace std;

int main()
{
	int errNumb = 0;
	int *const curErr = &errNumb;
	const double pi = 3.1415926;
	const double *const pip = &pi;

//	*pip = 2.72; // read only, cannot be reassigned
	
	if (*curErr){
		*curErr = 0;
	}

	cout << curErr << endl;
	cout << *curErr << endl;
	cout << hex << -123 << endl;
	int a = 0x7fffffff;
	cout << dec << 0x7fffffff + 1<< endl;

	return 0;
}
