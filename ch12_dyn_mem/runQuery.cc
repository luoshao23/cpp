#include <fstream>
#include <iostream>
#include <string>

#include "textQuery.h"

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or q to quit:";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
        // print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    std::ifstream file("text.txt");
    runQueries(file);
}