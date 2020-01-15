#include "StrVec.h"
#include <initializer_list>
#include <memory>
#include <iterator>
std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

// void StrVec::push_back(std::string &&s)
// {
//     chk_n_alloc();
//     alloc.construct(first_free++, std::move(s));
// }

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(b - e);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements){
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    size_t newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
    // auto dest = newdata;
    // auto elem = elements;
    // for (size_t i = 0; i < size(); ++i)
    //     alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = last;
    cap = elements + newcapacity;


}

StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec getVec(std::istream &is)
{
    StrVec stv;
    std::string s;
    while(is >> s)
        stv.push_back(s);
    return stv;
}

StrVec::~StrVec(){
    free();
}

StrVec::StrVec(StrVec &&s) noexcept
    :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, StrVec &s){
    std::string delim;
    for (auto st = s.begin(); st != s.end(); ++st){
        os << delim<< * st;
        delim = ", ";
    }
    return os;
}