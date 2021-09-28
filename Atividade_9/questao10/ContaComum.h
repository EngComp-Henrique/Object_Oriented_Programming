//
// Created by luis on 01/09/2021.
//

#ifndef CONTACOMUM_H
#define CONTACOMUM_H

#include "Conta.h"

class ContaComum: public Conta {
public:
    ContaComum(int valor, string nome, float saldo) : Conta(valor, nome, saldo) {};
    ContaComum() {};
    ~ContaComum() {};
    virtual void extrato();
    virtual bool debitar(float, int, int, int);
};


#endif
