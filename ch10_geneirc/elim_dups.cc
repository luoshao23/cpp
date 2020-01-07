#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_u = unique(words.begin(), words.end());
	words.erase(end_u, words.end());
}

void print(vector<string> &words) {
	for_each(words.cbegin(), words.cend(), [](const string &s){cout << s << " ";});
	cout << endl;
}

int main() {
	vector<string> svec = {"fox", "jump", "over", "the", "the", "fox"};
	print(svec);
	elimDups(svec);
	print(svec);

}
