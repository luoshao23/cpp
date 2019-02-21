#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> a1 = {1,2,3};
	vector<int> a2 = {1,2,3,4,5};
	cout << (a1 < a2) << endl;
	cout << (a1 > a2) << endl;

	return 0;
}
