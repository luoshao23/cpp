#include <iostream>


void printOut(int d){
    void printDigit(int);

    printDigit(d % 10);
    if (d >= 10)
        printOut(d / 10);


}

void printDigit(int n) {
    std::cout << n ;
}

int main(){
    int k;
    std::cin >> k;
    printOut(k);
    return 0;
}