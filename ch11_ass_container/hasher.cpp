#include <iostream>
#include <unordered_set>

using namespace std;

size_t hasher(const string &id)
{
    return hash<string>()(id);
}

bool eqOp(const string &s1, const string &s2)
{
    return s1 == s2;
}

int main()
{
    using sumset = unordered_multiset<string, decltype(hasher) *, decltype(eqOp) *>;
    sumset kcap(20, hasher, eqOp);
}
