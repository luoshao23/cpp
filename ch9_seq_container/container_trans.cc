#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	list<int> lint;
	for (int i = 0; i < 10; ++i)
		lint.push_back(i);

	vector<int> vint(lint.cbegin(), lint.cend());
	for (auto v: vint)
		cout << v ;

	cout << endl;

	for (auto l : lint)
		cout << l ;
	return 0;
}
