#include <iostream>
using namespace std;

int main(){
	unsigned cnt = 42;
	constexpr unsigned sz1 = 42;
	const int sz2 = 20;
	int arr1[10];
	int arr2[sz1];
	int arr3[sz2];

	arr2[1] = 3;
	cout << arr2 << endl;
	cout << arr2[1] << endl;

	int arr4[] = {5, 4, 2};
	char s1[] = "hithere";
	char s2[] = {'3', 'h'};
	const char a4[6] = "where";
	return 0;
}
