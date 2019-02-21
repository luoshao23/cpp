#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// auto f = []{ return 42; };
	//auto f = [](int &i){ i *= 2; };

	auto f = [](const int &i){ return 2 * i; };

	int k = 35;
	cout << f(k) << endl;

	vector<string> words = {"this", "is", "a", "string"};
	size_t sz = 4;
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
	auto wc = find_if(words.begin(), words.end(),
					  [sz](const string &a) { return a.size() >= sz; });
	cout << *wc << endl;
	for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
	cout << endl;
}
