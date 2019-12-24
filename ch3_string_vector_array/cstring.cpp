#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	char a[] = {'h', 'i'}; 
	//char a[] = "hi";
	char b[] = "lo";
	strcat(a, b);
	cout << a << " " << b;
	cout << strlen(a) << endl;
	string s1 = "hi, gril";
	const char *str = s1.c_str();
	cout << str << endl;
	cout << *str << endl;
	vector<char> cvec(begin(a), end(a));
	for (decltype(cvec.size()) i = 0; i < cvec.size(); ++i)
		cout << cvec[i] << endl;

	return 0;
}
