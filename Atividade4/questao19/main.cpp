#include <iostream>
#include "Data.h"

int main() {
    Data data1(23, 4, 2002);
    std::cout << "Dia: " << data1.getDia() << std::endl;
    std::cout << "Mês: " << data1.getMes() << std::endl;
    std::cout << "Ano: " << data1.getAno() << std::endl;
    data1.mostrarData();

    Data data2(33, -12, 2002);
    std::cout << "Dia: " << data2.getDia() << std::endl;
    std::cout << "Mês: " << data2.getMes() << std::endl;
    std::cout << "Ano: " << data2.getAno() << std::endl;
    data2.mostrarData();
    return 0;
}
