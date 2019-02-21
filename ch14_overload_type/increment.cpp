#include <string>

class Iter
{
public:
    Iter& operator--();
    Iter& operator++();
    Iter operator--(int);
    Iter operator++(int);

private:
    std::string *curr;
};