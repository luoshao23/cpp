#include <string>
#include <iostream>
using namespace std;

int main(){
	string str = "You are my sunshine!";
	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it);

	cout << str << endl;

	return 0;
}
