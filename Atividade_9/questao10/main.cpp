#include <iostream>
using std::cout, std::endl, std::cin;

#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"

int main() {
    char linha[] = "############################################\n";

    Conta *contas[3] = {new ContaComum(111328, "Luis", 5500),
                        new ContaLimite(111329, "Henrique", 2598.58, 3000),
                        new ContaPoupanca(221501, "Matheus", 1000, 23)
    };

    for (auto & conta : contas) {
        conta->extrato();
        cout << linha;
    }

    float valores[] = {100.50, -10000.58, -100, -720, 12000, 2000.56};
    int dias[] = {12, 25, 20, 31, 11, 30};
    int meses[] = {1, 2, 3, 10, 11, 12};
    int anos[] = {2015, 2015, 2015, 2015, 2015, 2015};
    int i;

    for (int j = 0; j < 6; j++) {
        i = j % 3;
        if (valores[j] > 0)
            contas[i]->creditar(valores[j], dias[j], meses[j], anos[j]);
        else
            contas[i]->debitar(valores[j], dias[j], meses[j], anos[j]);
    }

    for (auto & conta : contas) {
        conta->extrato();
        cout << linha;
    }

    for (auto & conta : contas) {
        delete conta;
    }
    return 0;
}
