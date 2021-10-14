#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

#include "Pessoa.h"

#include "InsufficientFundError.h"

#include <ctime>

#include <string>
using std::string;

class ContaPoupanca: public Conta {

    friend ContaPoupanca& operator>>(ContaPoupanca&, double);

    private:
        int Bday_acc, Bmonth_acc, Byear_acc;
    public:
        ContaPoupanca(string numConta, double balance, Pessoa* p, int d = 0, int m = 0, int y = 0) : Conta(numConta, balance, p) {
            if (d != 0 && m != 0 && y != 0) {
                time_t t;
                struct tm* info;
                time(&t);
                info = localtime(&t);
                Bday_acc = info->tm_mday;
                Bmonth_acc = info->tm_mon + 1;
                Byear_acc = info->tm_year + 1900;
            } else {
                Bday_acc = d;
                Bmonth_acc = m;
                Byear_acc = y;
            }
        }
        ContaPoupanca();
        ~ContaPoupanca() {};
        int getBday() const {return Bday_acc;}
        int getBmonth() const {return Bmonth_acc;}
        int getByear() const {return Byear_acc;}
        virtual void extrato() const;
        virtual void callWithdraw(double) const;
};


#endif