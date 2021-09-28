//
// Created by luis on 01/09/2021.
//

#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca: public Conta {
private:
    int conta_criada;
public:
    ContaPoupanca(int numConta, string nome, float saldo, int bd_conta) : Conta(numConta, nome, saldo), conta_criada(bd_conta) {}
    ContaPoupanca();
    ~ContaPoupanca() {};
    virtual void extrato();
    virtual bool debitar(float, int, int, int);
};


#endif
