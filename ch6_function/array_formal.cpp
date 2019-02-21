#include <iostream>
using namespace std;

void print(const int *p, size_t size)
{
	//for (auto s = p; s != p + size; ++s)
		//cout << *s << ",";
	for (size_t i = 0; i != size; ++i)
		cout << p[i] << ", ";
	cout << endl;
}

void print(int (&arr)[3])
{
	for (auto e : arr)
		cout << e << endl;
}

int main()
{
	int s[] = {12, 5, 2};
	//print(s, end(s) - begin(s));
	print(s);
	return 0;
}
