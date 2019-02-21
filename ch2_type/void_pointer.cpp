#include <iostream>
using namespace std;

int main()
{
	float k = 5.2, *pf = &k;
	double obj = 3.1415, *pd = &obj;
	void *pv = &obj;

	pv = pd;

	cout << pv << endl;
	pv = pf;
	cout << pv << endl;

	int ival = 1024;
	int *pi = &ival;
	int **ppi = &pi;
	cout << pi << endl;
	return 0;
}
