#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1;
	string s2 = s1;
	string s3 = "hwoo";
	string s4(10, 'x');
	string s5(s3);
	cout << s4 << endl;
	cout << s2 << endl;
	cout << s5 << endl;

	return 0;
}
