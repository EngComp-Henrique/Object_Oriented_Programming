//
// Created by luis on 26/08/2021.
//

#include "PessoaFisica.h"

#include <algorithm>

#include <iostream>
using std::string;

PessoaFisica::PessoaFisica(string aName, string cpf): Pessoa(aName) {
    setCpf(cpf);
}

PessoaFisica &PessoaFisica::setCpf(string newCpf) {
    if (newCpf.size() != 14 || !count_digits(newCpf) || !count_dots(newCpf) || !count_hairline(newCpf))
        this->cpf = "XXX.XXX.XXX-XX";
    else
        this->cpf = newCpf;
    return *this;
}

bool PessoaFisica::count_digits(string cpf) {
    int count = 0;
    for (auto s: cpf) {
        if (isdigit(s))
            count++;
    }
    if (count == 11)
        return true;
    return false;
}

bool PessoaFisica::count_dots(string cpf) {
    size_t n = std::count(cpf.begin(), cpf.end(), '.');
    if (n == 2)
        return true;
    return false;
}

bool PessoaFisica::count_hairline(string cpf) {
    size_t n = std::count(cpf.begin(), cpf.end(), '-');
    if (n == 1)
        return true;
    return false;
}

PessoaFisica::PessoaFisica() {

}
