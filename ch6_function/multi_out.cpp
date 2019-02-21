#include <iostream>
using namespace std;

string::size_type find_char(const string &s, char c,
		string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i < s.size(); ++i)
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	return ret;
}

bool is_sentence(const string &s)
{
	string::size_type ctr = 0;
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

int main()
{
	string s = "this is a sentence with multuple sss";
	string::size_type ctr;

	auto index = find_char("sdsdcsdcnsdicdn", 's', ctr);
	cout << index << "/" << ctr << endl;
	cout << is_sentence("we dwdw.") << endl;
	return 0;
}
