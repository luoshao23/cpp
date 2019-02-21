#include <iostream>
#include "ecode.h"
using namespace std;

void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for (const auto &elem : il)
		cout << elem << " ";
	cout << endl;
}
int main()
{
	string expected = "nice", actual;
	cin >> actual;

	if (expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	return 0;
}
