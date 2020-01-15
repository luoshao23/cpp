#ifndef STRVEC_H
#define STRVEC_H
#include <memory>
#include <utility>
#include <string>
#include <iostream>

class StrVec{
    friend StrVec getVec(std::istream &);
    friend std::ostream& operator<<(std::ostream&, StrVec&);
public:
    StrVec(): // allocator 成员进行默认初始化
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);                      // 拷贝构造函数
    StrVec(StrVec&&) noexcept;                  // *移动操作不应抛出任何异常*

    StrVec &operator=(const StrVec&);           // 拷贝赋值运算符
    StrVec &operator=(StrVec&&) noexcept;
    std::string& operator[](size_t i){ return elements[i]; }           // 拷贝赋值运算符
    ~StrVec();
    void push_back(const std::string&);         //  拷贝元素
    // void push_back(std::string&&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc(){ if (size() == capacity()) reallocate();}
    std::pair<std::string*, std::string*> alloc_n_copy(
        const std::string*, const std::string*
    );
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
#endif