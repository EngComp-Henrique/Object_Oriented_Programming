//
// Created by luis on 26/08/2021.
//

#include "Cliente.h"
#include <algorithm>
#include <iostream>

#include <ostream>
using std::ostream;

#include <string>
using std::endl, std::string;

ostream& operator<<(ostream& out, const Cliente& clt) {
    out << "Nome do cliente: " << clt.name << endl;
    out << "CPF do cliente: " << clt.getCpf() << endl;
    out << "Número de telefone: " << clt.getPhoneNumber() << endl;
    out << "Endeço: " << clt.getAddress() << endl;
    return out;
}

Cliente::Cliente(string aName, string aCpf, string number, string addr) : PessoaFisica(aName, aCpf), address(addr) {
    setPhoneNumber(number);
}

Cliente &Cliente::setPhoneNumber(string newPhoneNumber) {
    if (isAllDigits(newPhoneNumber) && countDash(newPhoneNumber))
        this->phoneNumber = newPhoneNumber;
    else
        this->phoneNumber = "XXXXX-XXXX";
    return *this;
}

Cliente &Cliente::setAddress(string newAddress) {
    this->address = newAddress;
    return *this;
}

bool Cliente::isAllDigits(string number) {
    if (number.size() != 10)
        return false;
    for (auto n: number) {
        if ((isdigit(n) == false) && (n != '-'))
            return false;
    }
    return true;
}

bool Cliente::countDash(string number) {
    size_t n = std::count(number.begin(), number.end(), '-');
    if (n == 1)
        return true;
    return false;
}
