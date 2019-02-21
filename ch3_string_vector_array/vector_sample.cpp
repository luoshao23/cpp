#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

int main()
{
	// initialization
	vector<int> ivec;
	vector<vector<int> > ivvec;
	vector<string> svect;
	string word;


	for (int i; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for (auto &c : ivec)
		std::cout << c << std::endl;

	while (std::cin >> word)
		svect.push_back(word);
	//std::cout << ivvec << std::endl;

	for (auto it = svect.begin(); it != svect.end(); ++it)
		std::cout << *it << std::endl;
	return 0;
}
