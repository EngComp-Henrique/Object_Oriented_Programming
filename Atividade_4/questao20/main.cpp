#include "Cupom.h"
#include <iostream>

int main() {
    Cupom cupom1("12334", "PC", 12, 10.50);
    std::cout << "Informações do cupom 1" << std::endl;
    cupom1.displayInfo();

    Cupom cupom2("190", "mouse", 20, 5);
    std::cout << "Informações do cupom 2" << std::endl;
    cupom2.displayInfo();

    Cupom cupom3("", "cabo", -12, -34);
    std::cout << "Informações do cupom 3" << std::endl;
    cupom3.displayInfo();

    return 0;
}
