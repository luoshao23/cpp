#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream myfile("e.txt");
	string s;
	if (myfile.is_open())
	{
		myfile >> s;
		myfile << "nice" << endl;
		myfile << "cool!" << endl;
	}
	else
		cout << "Unable to open file";
	cout << s;
	return 0;
}