#include <iostream>
using namespace std;

int main(){

	int (*func(const int i))[3];
	int (*arr)[3] = func(5);
	cout << arr << endl;
	cout << **arr << endl;

}

// this is wrong case since the returned value is freed after local
// scope is desctroyed
int (*func(const int i))[3]{
	int arr[3] = {i, i, i};
	int (*p)[3] = &arr;
	return p;
}
