#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
	vector<int> v1{2, 3, 4};
	vector<int> v2 = {9, 8, 7};
	vector<string> svec(5, "hi");

	for (auto s : svec)
		cout << s << endl;

	vector<string> v8{10, "wow"};
	vector<string> v9(10, "wow");

	for (auto s : v8)
		cout << s << endl;
	for (auto s : v9)
		cout << s << endl;

	return 0;
}
