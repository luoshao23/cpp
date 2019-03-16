#include <vector>
#include <list>
#include <string>
#include <initializer_list>
#include <iostream>

template <typename T> class Blob {
public:
    template <typename It> Blob(It b, It e);
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::shared_ptr<std::vector<T>> stype;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t);}
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    stype begin() { return data->begin(); }
    stype end() { return data->end(); }
    // auto end() -> decltype(data->end()) { return data->end(); }
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return  (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>) {}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e):
    data(std::make_shared<std::vector<T> >(b, e)) {}

template <typename It>
auto &fcn(It beg, It end) {
    return *beg;
}


int main()
{
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<const char*> w = {"now", "is", "the", "time"};
    Blob<int> a1(std::begin(ai), std::end(ai));
    Blob<int> a2(std::begin(vi), std::end(vi));
    Blob<std::string> a3(std::begin(w), std::end(w));

    for (std::size_t i = 0; i < squares.size(); ++i) {
        squares[i] *= squares[i];
        std::cout << squares[i] << std::endl;
    }
    for (std::size_t i = 0; i < a1.size(); ++i) {
        std::cout << a1[i] << std::endl;
    }
    for (std::size_t i = 0; i < a2.size(); ++i) {
        std::cout << a2[i] << std::endl;
    }
    for (std::size_t i = 0; i < a3.size(); ++i) {
        std::cout << a3[i] << std::endl;
    }

    auto &i = fcn(a3.begin(), a3.end());
    // std::cout << i << std::endl;

    return 0;
}