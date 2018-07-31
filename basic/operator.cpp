#include <iostream>
#include "Complex.h"

using namespace std;


int main(){
    Complex a1 = Complex(1, 2);
    Complex a2 = Complex(1);
    Complex a3 = Complex();
    Complex a4 = a1 + a2;

    cout << a1.re << "," << a1.im << endl;
    cout << a2.re << "," << a2.im << endl;
    cout << a3.re << "," << a3.im << endl;
    cout << a4.re << "," << a4.im << endl;

}