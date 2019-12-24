#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s1 = string("will") + "be";

	for (auto c : s1){
		if (ispunct(c)){
			cout << "*";

		} else {
			cout << c;
		}
	}
	return 0;
}
