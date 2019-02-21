#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

int main()
{
	vector<string> text = {"abc", "banana", "carbon", "kikk", "vba"};
	string sought = "kikk";
	auto beg = text.begin(), end = text.end();
	auto mid = beg + (end - beg) / 2;
	while (mid != end && *mid != sought)
	{
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}
	cout << *mid << " found" << endl;
	for (auto p = text.begin(); p != text.end(); p++)
	{
		cout << *p << endl;
	}
	return 0;
}
