#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> vi;

	for (int i=0; i < 100; ++i)
		vi.push_back(i);

	cout << vi[2] << endl;
}
