#ifndef CONTA_H
#define CONTA_H

#include "Pessoa.h"

#include "Transacoes.h"

#include "InsufficientFundError.h"

#include <vector>
using std::vector;

#include <ctime>

#include <string>
using std::string;

class Conta {

    friend Conta &operator<<( Conta &c, double sum) {
        if (sum >= 0) {
            time_t t;
            struct tm* info;
            time(&t);
            info = localtime(&t);
            int transaction_day = info->tm_mday;
            int transaction_month = info->tm_mon + 1;
            int transaction_year = info->tm_year + 1900;
            int transaction_hour = info->tm_hour;
            int transaction_min = info->tm_min;
            Transacoes newTransaction(transaction_day, transaction_month, transaction_year, transaction_hour, 
            transaction_min, "Valor depositado", sum);
            c.balance += sum;
            c.transactions.push_back(newTransaction);
        }
        return c;
    }

    friend Conta &operator>>( Conta& c, double sub) {
        c.callWithdraw(sub);
        c.setBalance(c.getBalance() - sub);
        return c;
    }

protected:
    string accountNumber;
    Pessoa* accountHolder;
    double balance;
    vector<Transacoes> transactions;
    const char *sep = "-------------------------------------------------------------\n";
public:
    Conta(string numAcc, double alloctedBalance, Pessoa* p) {
        setAccountNumber(numAcc);
        setBalance(alloctedBalance);
        accountHolder = p;
    };
    Conta() {};
    bool transfer(Conta* source, Conta* destiny, double v)
    {
        double value = source->getBalance() - v;
        if (value >= 0.0) {
            time_t t;
            struct tm* info;
            time(&t);
            info = localtime(&t);
            int transaction_day = info->tm_mday;
            int transaction_month = info->tm_mon + 1;
            int transaction_year = info->tm_year + 1900;
            int transaction_hour = info->tm_hour;
            int transaction_min = info->tm_min;
            string description_tranfer = "Transferência bancárias: " + source->getAccountHolder()->getName() + " -> " + 
            destiny->accountHolder->getName();
            Transacoes newTransaction(transaction_day, transaction_month, transaction_year, transaction_hour, 
            transaction_min, description_tranfer, value);
            double aux_dest = destiny->getBalance() + v;
            destiny->setBalance(aux_dest);
            source->setBalance(value);
            return true;
        } else {
            throw InsufficientFund();
        }
    }
    Conta& setAccountNumber(string newAccountNumber) {
        for (auto i: newAccountNumber) {
            if (!isdigit(i))
                throw WrongDataError();
        }
        this->accountNumber = newAccountNumber;
        return *this;
    }
    Conta& setBalance(double v) {
        if (v >= 0.0) {
            this->balance = v;
        } else {
            throw WrongDataError();
        }
        return *this;
    }
    Conta& setPessoa(Pessoa* p) {
        this->accountHolder = p;
        return *this;
    }
    void addTransaction(Transacoes t) {
        transactions.push_back(t);
    }
    vector<Transacoes> getTransactions() const {return transactions;}
    string getAccountNumber() const {return accountNumber;}
    Pessoa* getAccountHolder() {return accountHolder;}
    double getBalance() const {return balance;}
    void getOwnerInfo() const {accountHolder->getInfoAccount();}
    virtual ~Conta() {};
    virtual void extrato() const = 0;
    virtual void callWithdraw(double) const = 0;
};

#endif