#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void dedup(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

static inline void trunc(string &s)
{
	s.erase(find_if(s.rbegin(), s.rend(), [](int ch){
		return !(ch == ',' or ch == '.');
	}).base(), s.end());
}

static inline void trunc2(string &s)
{
	s.erase(s.find_last_not_of(",.")+1);
}

int main()
{

	ifstream f;
	vector<string> ss;
	string s;
	f.open("text.txt");
	while (f >> s) {
		trunc2(s);
		ss.push_back(s);
	}

	dedup(ss);
	for (auto e: ss)
		cout << e << endl;

	return 0;
}
