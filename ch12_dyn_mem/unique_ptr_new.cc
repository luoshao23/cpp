#include <memory>
using std::unique_ptr;

int main()
{
    unique_ptr<int[]> up(new int[10]);
    up.release();
}