#include <iostream>
using namespace std;

int main(){
	const size_t row = 3, col = 4;
	int a[row][col];
	int cnt = 0;

	for (auto &r : a){
		for (auto &c: r)
			c = ++cnt;
	}

	for (auto &r : a){
		for (auto &c: r){
			cout << c << ", ";
		}
		cout << endl;
	}

	cout << a << endl;
	return 0;
}
