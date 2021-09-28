//
// Created by luis on 01/09/2021.
//

#ifndef CONTALIMITE_H
#define CONTALIMITE_H

#include "Conta.h"

#include <string>
using std::string;

class ContaLimite: public Conta {
private:
    float limite;
public:
    ContaLimite(int numConta, string nome, float saldo, float lim): Conta(numConta, nome, saldo), limite(lim * -1) {};
    ContaLimite() {};
    ~ContaLimite() {};
    virtual void extrato();
    virtual bool debitar(float, int, int, int);
};


#endif
