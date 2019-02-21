#include <iostream>
using namespace std;

string screen(int ht = 24, int wid = 80, char back = ' ')
{
	string s = "@" + to_string(ht) + "=" + to_string(wid);
	return s;
}

int main()
{
	cout << screen() << endl;
	cout << screen(13) << endl;
	cout << screen(22, 9) << endl;

	return 0;
}
