#include <iostream>
using namespace std;

int main(){
	char c;
	while ((c = cin.get()) != EOF){ // receive all characters including invisible char
		cout << c << '!' << endl;
	}

	return 0;
}
