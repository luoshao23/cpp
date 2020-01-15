#include <iostream>
#include "HasPtr.h"

int main(){
    HasPtr p("Sd");
    p.display(std::cout) << std::endl;
    HasPtr g(p);
    p.display(std::cout) << std::endl;
    HasPtr k;
    k = p;
    p.display(std::cout) << std::endl;
    k.~HasPtr();
    p.display(std::cout) << std::endl;
    p.~HasPtr();
    p.display(std::cout) << std::endl;
    g.~HasPtr();
    p.display(std::cout) << std::endl;

}