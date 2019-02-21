#include <iostream>
using namespace std;

const string say(int i)
{
	return to_string(i);
}

const string apply(int i, const string k(int))
{
	return k(i);
}

int main()
{
	cout << apply(3, say) << endl;
	return 0;
}
