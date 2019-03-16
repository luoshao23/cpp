#include <iostream>
#include <string>
#include <vector>

class Ptr {
public:
    void push_back(const std::string&);
    std::string& operator*()
    {
        std::cout << "operator* ";
        return *svec.begin();
    }

    std::string* operator->()
    {
        return & this->operator*();
    }


private:
    std::vector<std::string> svec;

};

void Ptr::push_back(const std::string &s)
{
    svec.push_back(s);
}

int main()
{
    Ptr sv;
    std::string s = "nice";
    sv.push_back(s);
    std::cout << *sv << std::endl;
    return 0;
}