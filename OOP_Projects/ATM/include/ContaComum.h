#ifndef CONTACOMUM_H
#define CONTACOMUM_H

#include "Pessoa.h"

#include "Conta.h"

#include "InsufficientFundError.h"

#include <ctime>

#include <string>
using std::string;

class ContaComum : public Conta {
    friend ContaComum &operator>>( ContaComum &, double);

    public:
        ContaComum(string numRegister, Pessoa* p, double balance) : Conta(numRegister, balance, p) {};
        ContaComum() {};
        ~ContaComum() {};
        virtual void extrato() const;
        virtual void callWithdraw(double) const;
};


#endif