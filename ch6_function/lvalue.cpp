#include <iostream>
using namespace std;

char &get_val(string &str, string::size_type ix)
{
	return str[ix];
}

int main()
{
	string a = "a value";
	cout << a << endl;
	cout << get_val(a, 0) << endl;
	get_val(a, 0) = 'A';
	cout << a << endl;
	return 0;
}
