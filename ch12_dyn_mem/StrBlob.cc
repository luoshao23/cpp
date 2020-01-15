#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string& front();
    std::string& back();
    friend std::ostream& operator<< (std::ostream &os, const StrBlob &s);
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

std::ostream &operator<<(std::ostream &os, const StrBlob &s){
    for (auto begin = s.data->begin(), end = s.data->end(); begin != end; ++begin)
        os << *begin << ", ";
    return os;
}

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()){}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main()
{
    StrBlob b1;
    std::cout << b1 << std::endl;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    std::cout << b1 << std::endl;

    auto p1 = new auto(b1);
    std::cout << &b1 << std::endl;
    std::cout << p1 << std::endl;
    delete p1;

}