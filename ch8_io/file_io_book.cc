#include <iostream>
#include <string>
#include <fstream>
#include "../source_file/1/Sales_item.h"

int main(int argc, char * argv[]){
	std::string s;
	std::ifstream input;
	std::ofstream output;
	input.open(argv[1]);
	output.open(argv[2], std::ofstream::out);

	if (input && output){
		while (input >> s)
			output << "copy: " << s << std::endl;

		input.close();
		output.close();
	}else{
		std::cout << "open failed.";
	}

	return 0;
}
