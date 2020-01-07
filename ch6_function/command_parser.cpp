#include <iostream>
#include <vector>
#include "utils.h"

int main(int argc, char *argv[]){
    bool is_command(char *word);
    void alloc_command(char * word, std::string &command, std::vector<std::string> &values);

    int i = 1;
    std::string command;
    std::vector<std::string> values;

    while (i != argc){
        if (is_command(argv[i]))
        {
            // 处理上次的命令和值
            if (command.size() > 0 || values.size() > 0){
                std::cout << "The last command is " << command << ", and the values: ";
                for (auto v : values)
                    std::cout << v << ", ";
                std::cout << std::endl;
                values.clear();
            }

            alloc_command(argv[i], command, values);
            ++i;
            while (i != argc && !is_command(argv[i]))
            {
                values.push_back(argv[i]);
                ++i;
            }
        } else {
            values.push_back(argv[i]);
            ++i;
        }
    }
    std::cout << "The last command is " << command << ", and the values: ";
    for (auto v : values)
        std::cout << v << ", ";
    std::cout << std::endl;
    values.clear();

    return 0;

}

