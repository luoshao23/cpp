#include <iostream>
template <typename T> class ListItem;
template <typename T> class List {
public:
    List<T>();
    List<T>(const List<T> &);
    List<T>& operator=(const List<T> &);
    ~List();
    void insert(ListItem<T> *ptr, T value);
private:
    ListItem<T> *front, *end;
};

template<typename T>
bool comp_func(const T &v1, const T &v2) {
    if (v1 < v2) return true;
    if (v2 < v1) return false;
    return 0;
}

template <typename T, typename F = std::less<T> >
int compare(const T &v1, const T &v2, F f = F())
{
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}



int main()
{
    int res = compare(8, 8, comp_func<int>);
    std::cout << res << std::endl;
    return 0;
}