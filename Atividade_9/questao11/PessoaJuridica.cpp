//
// Created by luis on 02/09/2021.
//

#include "PessoaJuridica.h"

#include <algorithm>

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

PessoaJuridica::PessoaJuridica(string nome, string endr, string email, string CNPJ, string is, string rs) : Pessoa(nome, endr, email) {
    setCNPJ(CNPJ);
    setRazao_social(rs);
    setInsc_social(is);
}

PessoaJuridica &PessoaJuridica::setCNPJ(string new_cnpj) {
    if (new_cnpj.size() != 18 || !count_digits(new_cnpj) || !count_dots(new_cnpj) || !count_hairline(new_cnpj) ||
        !count_dash(new_cnpj))
        this->cnpj = "XX.XXX.XXX/0001-XX";
    else
        this->cnpj = new_cnpj;
    return *this;
}

PessoaJuridica &PessoaJuridica::setInsc_social(string insc_social) {
    this->insc_social = insc_social;
    return *this;
}

PessoaJuridica &PessoaJuridica::setRazao_social(string new_razao_social) {
    this->razao_social = new_razao_social;
    return *this;
}

void PessoaJuridica::verContato() const {
    cout << "Tipo de pessoa: JURIDÍCA" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CNPJ: " << getCpfOuCnpj() << endl;
    cout << "Enderço: " << getEndr() << endl;
    cout << "Razão social: " << getRazao_social() << endl;
    cout << "Inscrição social: " << getInsc_social() << endl;
    cout << "Email: " << getEmail() << endl;
}

bool PessoaJuridica::count_digits(string cnpj) {
    int count = 0;
    for (auto s: cnpj) {
        if (isdigit(s))
            count++;
    }
    if (count == 14)
        return true;
    return false;
}

bool PessoaJuridica::count_dots(string cnpj) {
    size_t n = std::count(cnpj.begin(), cnpj.end(), '.');
    if (n == 2)
        return true;
    return false;
}

bool PessoaJuridica::count_hairline(string cnpj) {
    size_t n = std::count(cnpj.begin(), cnpj.end(), '-');
    if (n == 1)
        return true;
    return false;
}

bool PessoaJuridica::count_dash(string cnpj) {
    size_t n = std::count(cnpj.begin(), cnpj.end(), '/');
    if (n == 1)
        return true;
    return false;
}

