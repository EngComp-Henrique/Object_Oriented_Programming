#include "Empregado.h"
#include <iostream>

int main() {
    Empregado funcionario1("Luis", "Santos", 5000);
    Empregado funcionario2("Henrique", "Lima", 30000);
    funcionario1.obterInfo();
    funcionario2.obterInfo();
    std::cout << "Aumento de 10% para todos os funcionário" << std::endl;
    double salarioMenFunc_1 = funcionario1.getSalario();
    double salarioMenFunc_2 = funcionario2.getSalario();
    funcionario1.setSalario(salarioMenFunc_1 * 0.10 + salarioMenFunc_1);
    funcionario2.setSalario(salarioMenFunc_2 * 0.10 + salarioMenFunc_2);
    funcionario1.obterInfo();
    funcionario2.obterInfo();
    return 0;
}
