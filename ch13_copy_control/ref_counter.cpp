#include <string>
#include <iostream>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
      ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr &p):
      ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
    std::string info(){ return *ps; }
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0){
        std::cout << *ps + " del!" << std::endl;
        delete ps;
        delete use;
    }
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

HasPtr& HasPtr::operator=(HasPtr &rhs)
{
    swap(*this, rhs);
    return *this;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}


int main()
{
    HasPtr temps("temp");
    HasPtr v1("v1");
    v1 = temps;
    std::cout << v1.info() << std::endl;
    std::cout << "Done" << std::endl;
}