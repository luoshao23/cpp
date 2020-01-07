#include <iterator>
#include <string>
using std::string; using std::find;

#include <iostream>
using std::cout; using  std::endl;

int main()
{
	string line = "FIRST, MIDDLE, LAST";
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	cout << string(line.crbegin(), rcomma) << "=" << endl;
	cout << string(rcomma.base(), line.cend()) << "=" << endl;

}
