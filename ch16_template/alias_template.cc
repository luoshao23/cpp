#include <utility>

//using template to rename a class
template<typename T> using twin = std::pair<T, T>;

int main()
{
	twin<int> k;
}
