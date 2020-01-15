#include <memory>
using std::unique_ptr;

int main()
{
    unique_ptr<int> first(new int(54));
    unique_ptr<int> second(first.release());

}