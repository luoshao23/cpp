#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class SizeComp{
public:
    SizeComp() = delete;
    SizeComp(size_t n): sz(n){}
    bool operator()(const std::string &s) const
        { return s.size() >= sz;}
private:
    size_t sz;
};

int main(){
    std::vector<std::string> words = {"sdss", "sd", "sdsdsada"};
    // size_t sz = 5;
    auto wc = std::find_if(words.begin(), words.end(), SizeComp(5));
    std::cout << *wc;
    // std::cout << cmp("nices") << "\n";
}