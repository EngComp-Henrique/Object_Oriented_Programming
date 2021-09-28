//
// Created by luis on 28/07/2021.
//

#ifndef CONTABANCO_H
#define CONTABANCO_H

class ContaBanco {

private:
    double saldo;

public:
    ContaBanco(double valor);
    void setSaldo(double valor);
    void creditar(double valorAdicionado);
    void debitar(double valorRetirado);
    double getSaldo();
};

#endif
