//
// Created by luis on 01/09/2021.
//

#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include "Transacoes.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

class Conta {
protected:
    int numero_conta;
    string nome;
    float saldo;
    vector<Transacoes> historico;
    const char *sep = "--------------------------------------------\n";
public:
    Conta(int numConta, string nomeCorre, float saldoAlocado) : numero_conta(numConta), nome(nomeCorre), saldo(saldoAlocado) {};
    Conta() {};
    virtual ~Conta() {};
    bool creditar(float valor, int d, int m , int a) {
        if (valor > 0) {
            this->saldo += valor;
            Transacoes t(d, m, a, "CREDITOU", valor);
            historico.push_back(t);
            return true;
        }
        return false;
    }
    virtual bool debitar(float, int, int, int) = 0;
    virtual void extrato() = 0;
};


#endif
