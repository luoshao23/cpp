#include <iostream>
using namespace std;

int main(){
	int ia[] = {2, 4, 7, 5, 8};
	int *b = begin(ia);
	int *e = end(ia);

	//for (auto c = b; c != e; ++c)
	for (decltype(b) c = b; c != e; ++c)
		cout << *c << endl;
	int *p = ia + 5;
	int *p2 = ia + 10;

	return 0;
}
