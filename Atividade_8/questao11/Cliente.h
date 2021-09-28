//
// Created by luis on 26/08/2021.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "PessoaFisica.h"

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class Cliente: public PessoaFisica{
    friend ostream& operator<<(ostream&, const Cliente&);
private:
    string phoneNumber;
    string address;
    bool isAllDigits(string);
    bool countDash(string);
public:
    Cliente(string, string, string, string);
    Cliente();
    string getPhoneNumber() const {return phoneNumber;}
    string getAddress() const {return address;}
    Cliente& setPhoneNumber(string);
    Cliente& setAddress(string);
};


#endif
