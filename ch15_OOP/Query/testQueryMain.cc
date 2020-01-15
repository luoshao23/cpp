#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Query.h"
#include "textQuery.h"


int main()
{
    std::ifstream file("text.txt");
    TextQuery tq(file);
    std::string aLine;
    // print(std::cout, tq.query("we")) << std::endl;
    while (std::getline(std::cin, aLine))
    {
        std::istringstream words(aLine);
        std::string word;
        std::vector<std::string> vwords;
        while(words >> word)
            vwords.push_back(word);

        switch (vwords.size())
        {
        case 3:
            if (vwords[1] == "|" ) {
                auto orQ = Query(vwords[0]) | Query(vwords[2]);
                auto res = orQ.eval(tq);
                print(std::cout, res);
            } else if (vwords[1] == "&"){
                auto andQ = Query(vwords[0]) & Query(vwords[2]);
                auto res = andQ.eval(tq);
                print(std::cout, res);
            } else {
                std::cout << "continue" << std::endl;
            }
            break;
        case 2:
            if (vwords[0] == "~"){
                auto notQ = ~Query(vwords[1]);
                auto res = notQ.eval(tq);
                print(std::cout, res);
            } else {
                std::cout << "continue" << std::endl;
            }
            break;
        case 1:
            {auto wQ = Query(vwords[0]);
            auto res = wQ.eval(tq);
            print(std::cout, res);}
            break;

        default:
            std::cout << "continue" << std::endl;
            break;
        }

    }

}