#include <iostream>
#include <string>

using namespace std;

int main(){

	string s("C++ Primer"), s2 = s;
	s.insert(s.size(), " 4th Ed.");
	s2.append(" 4th Ed.");
	cout << s << endl;
	cout << s2 << endl;

	s.erase(11, 3);
	s.insert(11, "5th");
	s2.replace(11, 3, "5th");
	cout << s << endl;
	cout << s2 << endl;
	s2.replace(11, 3, "Fifth");
	cout << s << endl;
	cout << s2 << endl;

	return 0;
}
