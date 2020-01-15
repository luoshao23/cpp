#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const std::string &nums) {
	if (nums.size() != 11)
		return false;

	for (auto c : nums) {
		if (!(c >= '0' && c <= '9'))
			return false;
	}
	return true;
}

std::string format(const std::string &nums) {
	std::string formattedNum;
	for (decltype(nums.size()) i = 0; i < 11; ++i) {
		if (i == 3 || i == 7)
			formattedNum += '-';
		formattedNum += nums[i];

	}
	return formattedNum;
}

int main() {
	string word, line;
	vector<PersonInfo> lists;
	bool valid(const std::string &nums);
	std::string format(const std::string &nums);
	
	while (getline(cin, line)) {
		PersonInfo tmp_info;
		istringstream record(line);
		record >> tmp_info.name;
		while (record >> word)
			tmp_info.phones.push_back(word);
		lists.push_back(tmp_info);
	}

	for (const auto &entry : lists) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			} else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			std::cout << entry.name << " "
				    << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name 
				    << " invalid number(s) " << badNums.str() << std::endl;
	}
	
//	for (auto p: lists){
//		int cnt = 0;
//		cout << "name: " << p.name << " ";
//		for (auto i : p.phones)
//			cout << "phone" << ++cnt << ": " << i << " ";
//		cout << endl;
//	}

	return 0;
}

