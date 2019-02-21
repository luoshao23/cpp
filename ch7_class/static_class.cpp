#include <iostream>
#include "Account.h"
using namespace std;



int main()
{
	double r;
	// Account a;
	// Account *p;
	// p = &a;

	r = Account::rate();
	cout << r;
	return 0;
}
