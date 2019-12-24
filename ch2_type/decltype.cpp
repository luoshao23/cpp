#include <iostream>
using namespace std;

int main(){
	int f(int a);
	// decltype(f) sum = 2.0;
	decltype(f(2)) sum2 = 3.0;
	cout << ((5)) << endl;
	return 0;
}

int f(int a){
	return a + 1;
}
