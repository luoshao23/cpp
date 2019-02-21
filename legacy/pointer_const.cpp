#include <iostream>
using namespace std;

void f1()
{
    char s[] = "Shellder";
    const char *p1 = s;
    // p1[3] = 'S'; // read-only variable is not assignable
    p1 = "nice";
    cout << *p1 << endl;

    char *const p2 = s;
    p2[3] = 'F';
    // p2 = "nice"; // cannot assign to variable 'p2' with const-qualified type 'char *const'
    cout << *(p2 + 3) << endl;

    int ii = 0;
    int *p3 = &ii;
    ii++;
    cout << *p3 << endl;
}

void increment(int& aa) { aa++; }
int next(int p) { return p + 1; }
void incr(int *p) { (*p)++; }

void f2()
{
    int x = 0;
    cout << x << endl;
    increment(x);
    cout << x << endl;
    x = next(x);
    cout << x << endl;
    incr(&x);
    cout << x << endl;

}

int main()
{
    // f1();
    f2();

    return 0;
}