#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T const& Max (T const& a, T const& b)
{
    return a < b? b:a;
}

template <class T>
class Stack{
    private:
        vector<T> elems;
    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const{
            return elems.empty();
        }
};

template <class T>
void Stack<T>::push (T const& elem)
{
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

int main()
{
    int i = 38;
    int j = 23;
    cout << Max(i, j) << endl;

    string a = "Nice";
    string b = "Cool";
    cout << Max(a, b) << endl;


    try
    {
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(7);
        cout << intStack.top() << endl;
        // intStack.pop();
        cout << intStack.top() << endl;

        stringStack.push("Hello");
        stringStack.push("World");
        cout << stringStack.top() << endl;
        stringStack.pop();
        cout << stringStack.top() << endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}