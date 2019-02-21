#include <iostream>
using namespace std;

int main()
{
	string nums[] = {"one", "two", "three"};
	string *p = &nums[0];
	string *p2 = nums;
	cout << (p == p2) << endl;
	string txt[] = {"we", "are", "the", "champion"};
	string *k = &txt[2];
	cout << k[1] << endl;
	cout << k[-1] << endl;
	return 0;
}
