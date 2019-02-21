#include <string>
#include <iostream>
#include <initializer_list>

#define  _SCL_SECURE_NO_WARNINGS

class StrVec
{
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec&);
    StrVec &operator=(std::initializer_list<std::string>);
    StrVec &operator=(StrVec&&) noexcept;
    std::string& operator[](std::size_t n) { return elements[n]; }
    const std::string& operator[](std::size_t n) const { return elements[n]; }
    ~StrVec();
    void push_back(const std::string&);
    void push_back(std::string&&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s)
{
    std::cout << "const version" << std::endl;
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
    std::cout << "move copy version" << std::endl;
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
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


void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                   make_move_iterator(end()),
                                   first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
    // auto newdata = alloc.allocate(newcapacity);
    // auto dest = newdata;
    // auto elem = elements;

    // for (size_t i = 0; i != size(); ++i)
    //     alloc.construct(dest++, std::move(*elem++));

    // free();
    // elements = newdata;
    // first_free = dest;
    // cap = elements + newcapacity;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}



int main()
{
    StrVec ss({"sd", "asd"});
    StrVec ss2;
    ss2 = ss;
    std::string s = "const";
    ss2.push_back(s);
    ss2.push_back("move");
    for (auto p : ss)
        std::cout << p << std::endl;
    for (auto p : ss2)
        std::cout << p << std::endl;

    ss[1] = "nice";
    const StrVec cvec = ss;

    std::cout << ss2[1] << std::endl;
    std::cout << cvec[1] << std::endl;
    // cvec[1] = "bad";

    return 0;
}