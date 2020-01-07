#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main() {
	istream_iterator<int> cas(cin), eof;
	vector<int> ivec(cas, eof);
	//for (auto i: ivec)
	//	cout << i << endl;
	
	ostream_iterator<int> out(cout, ", ");
	for (auto i: ivec)
		*out++ = i;
	cout << endl;

	ostream_iterator<int> out_it(cout, ":");
	copy(ivec.cbegin(), ivec.cend(), out_it);
}
