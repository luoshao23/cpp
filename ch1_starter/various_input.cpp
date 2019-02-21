#include <iostream>
using namespace std;

int main(){
	int sum = 0, val = 0;
	while(cin >> val)
	{
		cout << "Input " << val << endl;
		sum += val;
	}
	cout << "The sum is " << sum << endl;

	return 0;
}
