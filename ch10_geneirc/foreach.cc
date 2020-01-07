#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	string const_str = "Yes!";
	string tmp_s;
	vector<string> svec;

	while (cin >> tmp_s) {
		svec.push_back(tmp_s);
	}
	for_each(svec.begin(), svec.end(), [const_str](const string& word)
			{ cout << const_str << " " << word << "! ";});
	cout << endl;
}
