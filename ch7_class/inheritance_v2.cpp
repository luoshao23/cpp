#include <iostream>

using namespace std;

class Base1 {
public:
    Base1(int a): m_a(a) {}

protected:
    int m_a;
};

class Base2 {
public:
    Base2(int b, int c): m_b(b), m_c(c) {}
    Base2() : m_b(0), m_c(0) {}

protected:
    int m_b;
    int m_c;
};

class Intermediate1 : public Base1, virtual public Base2 {
public:
    Intermediate1(int a, int b, int c)
        : Base1(a),
          Base2(b, c)
    {

    }
};

class Intermediate2 : public Intermediate1 {
public:
    Intermediate2(int a, int b, int c)
        : Intermediate1(a, b, c),
          Base2(b, c)
    {

    }
};

class Intermediate3 : virtual public Base2 {
public:
    Intermediate3(int b, int c)
        : Base2(b, c)
    {

    }
};

class Final : public Intermediate2, public Intermediate3 {
public:
  Final(int a, int b, int c)
      : //Base2(b, c), // 如果在继承链上存在虚继承的基类，则最底层的子类要负责完成该虚基类部分成员的构造
        Intermediate2(a, b, c),
        Intermediate3(b, c)
  {

    }

    void Print() {
        cout<<m_a<<", "<<m_b<<", "<<m_c<<endl;
    }
};


int main(int argc, char* argv[])
{
    Final finalObj(1, 2, 3);
    finalObj.Print();

    return 0;
}