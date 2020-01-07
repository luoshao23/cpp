#include<list>
using std::list;
#include <iostream>
using std::cout; using std::endl;

int main()
{
	list<int> v1{2, 4, 5};	
	list<int> v2{12,99,0};

	v1.merge(v2);

	for (auto i: v1)
		cout << i << endl;
}
