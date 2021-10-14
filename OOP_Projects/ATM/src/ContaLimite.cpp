#include "../include/ContaLimite.h"

#include <iostream>
using std::cout;
using std::endl;
using std::left;
using std::right;

#include <iomanip>
using std::setfill;
using std::setw;

#include <ctime>

#include <iomanip>
using std::setprecision;
using std::fixed;
using std::setfill;

ContaLimite& operator>>(ContaLimite& c, double sub) {
    auto auxBalance = c.getBalance();
    c.callWithdraw(sub);
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
    transaction_min, "Valor sacado", sub);
    c.setBalance(auxBalance - sub);
    c.addTransaction(newTransaction);
    return c;
}

void ContaLimite::extrato() const {
    cout << "Informações do titular da conta: " << endl;
    getOwnerInfo();
    cout << "Número da conta:" << left << setfill('.') << setw(9) << " " << getAccountNumber() << endl;
    if (!transactions.empty()) {
        cout << "TRANSAÇÕES" << endl << endl;
        for (auto & i : transactions) {
            cout << "Data:" << left << setfill('.') << setw(20) << " " << right << setfill('0') << setw(2) << i.get_Tday() << "/" << 
            setfill('0') << setw(2) << i.get_Tmonth() << "/" << i.get_Tyear() << endl;
            cout << "Descrição:" << left << setfill('.') << setw(15) << " " << i.getDescription() << endl;
            if (i.getAmount() > 0)
                cout << "Valor depositado ";
            else
                cout << "Valor retirado ";
            cout << fixed;
            cout << setprecision(2) << "(R$):" << left << setfill('.') << setw(5) <<  " " << i.getAmount() << endl;
            cout << sep << endl;
        }
    } else {
        cout << "Sem transações até o momento." << endl;
    }
    cout << fixed;
    cout << setprecision(2) << "Saldo atual (R$):" << left << setfill('.') << setw(7) << " " << getBalance() << endl;
    cout << setprecision(2) << "Limite de crédito (R$):" << left << setfill('.') << setw(2) << " " << getLimit() << endl;
}

void ContaLimite::callWithdraw(double v) const {
    if (v + getBalance() > getLimit())
        throw ExceedLimit();
    if (v < 0)
        throw WrongDataError();
}

ContaLimite& ContaLimite::setLimit(double v) {
    if (v < 0) 
        throw WrongDataError();
    else 
        this->limit = v;
    return *this;
}