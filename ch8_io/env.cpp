#include <iostream>

using namespace std;

int main(int argc, char* argv[], char* envp[])
{
	for (int i = 0; i < argc; ++i){
		cout << argv[i] << endl;
	}
	for (int i = 0; i < argc; ++i)
	{
		cout << envp[i] << endl;
	}
	cout << envp;

	return 0;
}
