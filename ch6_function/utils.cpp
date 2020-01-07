#include <cstring>
#include <string>
#include <vector>
#include "utils.h"

bool is_command(char *word){

    return  !(sizeof(word) / sizeof(char) <= 1 || word[0] != '-');
    // {
    //     return false;
    // }
    // return true;
}

void alloc_command(char *word, std::string &command, std::vector<std::string> &values){
    if (std::strncmp("--", word, 2) == 0){
        command = std::string(word + 2);
    }
    else if (word[0] == '-') {
        command = word[1];
        if (std::string(word + 2).size() > 0)
            values.push_back(std::string(word + 2));
    }
}
