#include <iostream>
#include <string>

using namespace std;

void replace_all(string &s, string oldVal, string newVal)
{
	int lenOld = oldVal.size();
	int lenNew = newVal.size();
	size_t pos = 0;
	while (pos < s.length()) {
		pos = s.find(oldVal, pos);
		if (pos >= s.length()) break;
		s.erase(pos, lenOld);
		s.insert(pos, newVal);
		pos += lenNew;
	}

}

void replace_all_iter(string &s, string oldVal, string newVal)
{
	int lenOld = oldVal.size();
	int lenNew = newVal.size();
	auto be = s.begin();
	while (be != s.end()) {
		size_t iter = 0;
		for (size_t i = 0; i < lenOld; ++i) {
			if (*(be+i) != oldVal[i]) break;
			++iter;
		}
		if (iter == oldVal.length()) {
			s.erase(be, be + lenOld);
			s.insert(be, newVal.begin(), newVal.end());
			be += lenNew;
		} else {
			++be;
		}
	}
}

int main(){

	string a1 = "luo sasdasdluocsdcsd";
	string old = "luo";
	string ne = "NB";

	cout << a1 << endl;
	replace_all_iter(a1, old, ne);
	cout << a1 << endl;

	return 0;
}
