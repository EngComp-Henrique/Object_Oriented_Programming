//
// Created by luis on 01/09/2021.
//

#include "ContaLimite.h"

#include <iostream>
using std::cout, std::endl;

#include <iomanip>
using std::setfill, std::setw;

void ContaLimite::extrato() {
    cout << "Número da conta: " << numero_conta << endl;
    cout << "Nome do cliente: " << nome << endl;
    if (!historico.empty()) {
        for (auto & i : historico) {
            cout << "Data: " << setfill('0') << setw(2) << i.getDia() << "/" << setfill('0') << setw(2)
                 << i.getMes() << "/" << i.getAno() << endl;
            cout << "Descrição: \"" << i.getDesc() << "\"" << endl;
            if (i.getValor() > 0)
                cout << "Valor adicionado";
            else
                cout << "Valor retirado";
            cout << " (R$): " << i.getValor() << endl;
            cout << sep << endl;
        }
    } else {
        cout << "Sem transações até o momento." << endl;
    }
    cout << "Saldo atual (R$): " << saldo << endl;
    cout << "Limte da conta (R$): " << limite << endl;
}

bool ContaLimite::debitar(float valor, int d, int m , int a) {
    if (this->saldo + valor >= this->limite) {
        this->saldo += valor;
        Transacoes t(d, m, a, "DEBITOU", valor);
        historico.push_back(t);
        return true;
    } else {
        cout << sep << endl;
        cout << "Cliente " << nome << ", não é possível realizar essa operação" << endl;
        cout << "Saldo atual (R$): " << saldo << endl;
        cout << "Limte da conta (R$): " << limite << endl;
        cout << sep << endl;
    }
    return false;
}
