#include <iostream>
#include <string>
using namespace std;

int main(){
	bool (*pd)(const string&, const string&);
	bool len_comp(const string &s1, const string &s2);
	pd = len_comp;

	cout << pd("hi", "sdsdsd") << endl;
	cout << (*pd)("hsssssssssssi", "sdsdsd") << endl;
}

bool len_comp(const string &s1, const string &s2){
	return s1.size() > s2.size();
}
