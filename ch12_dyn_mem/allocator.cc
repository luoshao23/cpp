#include <memory>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vi = {1, 2, 3, 4};
    allocator<int> alloc;
    auto p = alloc.allocate(vi.size() * 2);
    // for (auto g = p; g < p + vi.size() * 2; ++g)
    //     cout << *g << ", ";
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    // for (auto g = p; g < p + vi.size() * 2; ++g)
    //     cout << *g << ", ";
    auto x = uninitialized_fill_n(q, vi.size(), 22);
    for (auto g = p; g < p + vi.size() * 2; ++g)
        cout << *g << ", ";
    while (x != p)
        alloc.destroy(--x);
    alloc.deallocate(p, vi.size() * 2);
}