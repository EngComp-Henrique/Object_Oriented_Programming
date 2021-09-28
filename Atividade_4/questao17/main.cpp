//
// Created by luis on 28/07/2021.
//

#include <iostream>
#include "ContaBanco.h"
using std::cout, std::endl;

int main() {
    ContaBanco cliente1(500.78);

    cout << "Operações do cliente 1" << endl;
    cout << "Valor do saldo atual: " << cliente1.getSaldo() << endl;
    cliente1.creditar(500);
    cout << "Valor do saldo após adição de crédito: " << cliente1.getSaldo() << endl;
    cliente1.debitar(700.58);
    cout << "Valor do saldo após débito: " << cliente1.getSaldo() << endl;

    cout << endl;

    ContaBanco cliente2(-1500);

    cout << "Operações do cliente 2" << endl;
    cout << "Valor do saldo atual: " << cliente2.getSaldo() << endl;
    cliente2.creditar(1500.90);
    cout << "Valor do saldo após adição de crédito: " << cliente2.getSaldo() << endl;
    cliente2.debitar(2000);
    cout << "Valor do saldo após débito: " << cliente2.getSaldo() << endl;
    return 0;
}
