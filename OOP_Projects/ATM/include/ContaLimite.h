#ifndef CONTALIMITE_H
#define CONTALIMITE_H

#include "Conta.h"

#include "Pessoa.h"

#include "ExceedLimitError.h"

#include "../include/WrongDataError.h"

#include <ctime>

#include <string>
using std::string;

class ContaLimite: public Conta {

    friend ContaLimite& operator>>(ContaLimite&, double);

    private:
        double limit;
    public:
        ContaLimite(string numAcc, double balan, Pessoa* p , double lim): Conta(numAcc, balan, p) {
            setLimit(lim);
        };
        ContaLimite() {};
        ~ContaLimite() {};
        ContaLimite& setLimit(double);
        double getLimit() const {return limit;}
        virtual void extrato() const;
        virtual void callWithdraw(double) const;
};


#endif