#include <iostream>
using namespace std;

class numbered {
public:
    numbered();
    numbered(const numbered&);
    int mysn;
private:
    static int seq;
};

int numbered::seq = 0;

numbered::numbered(){
    cout << "合成拷贝" << endl;
    mysn = seq++;
}

numbered::numbered(const numbered &s){
    cout << "赋值拷贝" << endl;
    mysn = seq++;
}

// void f(numbered s) { cout << s.mysn << endl; }
void f(numbered& s) { cout << s.mysn << endl; }

int main(){
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

}