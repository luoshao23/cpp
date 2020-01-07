#include <iostream>
using namespace std;

int main(){
	void print(int (&arr)[4]);
	int k[] = {1, 4, 6, 5};
	print(k);

	return 0;
}

void print(int (&arr)[4]){
	for (auto a : arr)
		cout << a << endl;
}
