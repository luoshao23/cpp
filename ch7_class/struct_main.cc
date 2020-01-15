#include "class_struct.h"
#include <iostream>

using namespace std;

int main(){
	Sales_data s1;
	Sales_data total;

	while (read(cin, s1)){
		total.combine(s1);
		print(cout, total);
	}

	return 0;
}
