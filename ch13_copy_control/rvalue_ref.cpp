#include <vector>

int main()
{
    int f();
    std::vector<int> vi(100);

    int&& r1 = f();
    int& r2 = vi[0];
    int& r3 = r1;
    int&& r4 = vi[0] * f();
    return 0;
}

int f()
{
    return 3;
}