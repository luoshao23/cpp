#include <iostream>
using namespace std;

int main()
{
	auto old_state = cin.rdstate();
	cout << old_state << endl;
	cin.clear();
	old_state = cin.rdstate();
	cout << old_state << endl;

	cout << "hi! endl" << endl;
	cout << "hi! flush" << flush;
	cout << "hi! ends" << ends;

	return 0;
}
