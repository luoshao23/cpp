#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	try {
		if (n > 100)
			cout << "OK" << endl;
		else
			throw runtime_error("<Error 1: missing>");
	} catch (runtime_error e) {
		cout << e.what() << " occurred" << endl;
		cout << "handle error..." << endl;
	}
	return 0;
}
