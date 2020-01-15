#include <iostream>
#include <algorithm>

// type parameter, 非类型参数
template <typename T, typename U = std::less<T> >
int compare(const T &v1, const T &v2, U comp = U())
{
    if (comp(v1, v2)) return -1;
    if (comp(v2, v1)) return 1;
    return 0;
}

// // nontype parameter, 非类型参数
// template <unsigned N, unsigned M>
// int compare(const char (&p)[N], const char (&q)[M])
// {
//     return strcmp(p, q);
// }

int main()
{
    std::cout << compare("hi", "mo") << std::endl;
}

//
// #include <functional>
// #include <iostream>

// template <typename A, typename B, typename U = std::less<>>
// bool f(A a, B b, U u = U())
// {
//     return u(a, b);
// }

// int main()
// {
//     std::cout << std::boolalpha;
//     std::cout << f(5, 20) << '\n';
//     std::cout << f(100, 10) << '\n';
// }