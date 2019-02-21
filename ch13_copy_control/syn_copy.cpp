#include <iostream>

using namespace std;

class Numbered
{
public:
    Numbered(){ mySeq = num++; }
    Numbered(const Numbered& i){ mySeq = num++; }
    int mySeq;
private:
    static int num;
};

int Numbered::num = 0;

void f1(Numbered s)
{
    cout << s.mySeq << endl;
}

void f2(const Numbered& s)
{
    cout << s.mySeq << endl;
}

int main()
{
    Numbered a, b = a, c = b;
    f2(a);
    f2(b);
    f2(c);

    f1(a);
    f1(b);
    f1(c);

    return 0;
}