#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> words = {"this", "is", "a", "line."};

	for (auto e: words)
		cout << e << endl;

	sort(words.begin(), words.end(), isShorter);

	for (auto e: words)
		cout << e << endl;
	return 0;
}
