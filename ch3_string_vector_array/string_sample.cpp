#include <iostream>
#include <string>
using namespace std;
using std::string;

int main()
{
	string s1;
	string s2 = s1;
	string s3 = "nice";
	string s4(10, 's');

	cout << s1 << s2 << s3 << s4 << endl;

	string s5 = "asd" + s4 + "part1" + "part2";
	cout << s5 << endl;
	
	string line;
	//while (getline(cin, line))
	//	if (!line.empty() && line.size() < 10)
	//		for (auto c : line)
	//			cout << c << "," ;
	string s("Hello world!");
	decltype(s.size()) punct_size = 0;
	for (auto &c : s){
		c = toupper(c);
		if (ispunct(c))
			++punct_size;
	}
	cout << s << endl;
	cout << punct_size << " punctuation characters in " << s << endl;

	s[1] = '4';
	cout << s << endl;
	
	return 0;

}
