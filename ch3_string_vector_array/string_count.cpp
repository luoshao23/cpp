#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s1;
	//cin >> s1 ;
	getline(cin, s1);
	decltype(s1.size()) count = 0;

	for (auto &c : s1){
		if (ispunct(c)){
			++count;
		} else {
			c = toupper(c);
		}
	}
	cout << s1
		<< " has " << count << " punctuation character(s)."<< endl;
	return 0;
}
