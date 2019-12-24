#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s("some string");

	if (!s.empty())
		s[0] = toupper(s[0]);
	cout << s << endl;

	for (decltype(s.size()) i = 0; i != s.size() && !isspace(s[i]); ++i)
		s[i] = toupper(s[i]);

	cout << s << endl;
	
	string s2;
	cout << s2[0] << endl;

	return 0;
}
