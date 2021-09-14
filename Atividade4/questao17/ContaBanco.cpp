//
// Created by luis on 28/07/2021.
//

#include "ContaBanco.h"
#include <iostream>
using std::cout, std::endl;

ContaBanco::ContaBanco(double valor) {
    setSaldo(valor);
}

void ContaBanco::setSaldo(double valor){
    if (valor <= 0)
        saldo = 0;
    else
        saldo = valor;
}

void ContaBanco::creditar(double valorAdicionado) {
    saldo += valorAdicionado;
}
void ContaBanco::debitar(double valorRetirado) {
    if (saldo - valorRetirado >= 0)
        saldo -= valorRetirado;
    else
        cout << "ERRO! Quantia debitada maior do que a disponível.\nValor atualmente disponível (R$): " << getSaldo() << endl;
}

double ContaBanco::getSaldo() {
    return saldo;
}