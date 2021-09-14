//
// Created by luis on 02/09/2021.
//

#include "PessoaFisica.h"

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <algorithm>

PessoaFisica::PessoaFisica(string nome, string endr, string email, string CPF, string ec, string dn) : Pessoa(nome, endr, email),
estadoCivil(ec), data_nasc(dn)
{
    setCpf(CPF);
};

PessoaFisica &PessoaFisica::setCpf(string newCpf) {
    if (newCpf.size() != 14 || !count_digits(newCpf) || !count_dots(newCpf) || !count_hairline(newCpf))
        this->cpf = "XXX.XXX.XXX-XX";
    else
        this->cpf = newCpf;
    return *this;
}

void PessoaFisica::verContato() const {
    cout << "Tipo de pessoa: FISÍCA" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCpfOuCnpj() << endl;
    cout << "Endereço: " << getEndr() << endl;
    cout << "Estado civil: " << getEstCivil() << endl;
    cout << "Data de nacimento: " << getNasc() << endl;
    cout << "Email: " << getEmail() << endl;
}

bool PessoaFisica::count_digits(string cpf_analisado) {
    int count = 0;
    for (auto s: cpf_analisado) {
        if (isdigit(s))
            count++;
    }
    if (count == 11)
        return true;
    return false;
}

bool PessoaFisica::count_dots(string cpf_analisado) {
    size_t n = std::count(cpf_analisado.begin(), cpf_analisado.end(), '.');
    if (n == 2)
        return true;
    return false;
}

bool PessoaFisica::count_hairline(string cpf_analisado) {
    size_t n = std::count(cpf_analisado.begin(), cpf_analisado.end(), '-');
    if (n == 1)
        return true;
    return false;
}



