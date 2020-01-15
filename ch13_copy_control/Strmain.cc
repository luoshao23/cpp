#include <string>
#include <iostream>
#include "StrVec.h"


int main()
{
    StrVec sv;
    for (int i = 0; i < 5; ++i)
        sv.push_back(std::to_string(i));
    sv.push_back("nice");

    // for (int i = 0; i < 5; ++i)
    //     std::cout << sv[i] << ", ";
    // std::cout << std::endl;


    std::cout << sv << std::endl;
}

// int main(){
//     std::string s[] = {"sd", "ss", "d"};
//     std::string* k = s;
//     std::cout << k[1] << std::endl;

// }