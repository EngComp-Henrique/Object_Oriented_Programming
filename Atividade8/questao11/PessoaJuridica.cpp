//
// Created by luis on 26/08/2021.
//

#include "PessoaJuridica.h"

#include <algorithm>

#include <string>
using std::string;

PessoaJuridica::PessoaJuridica(string aName, string aCnpj, string rs, string nf): Pessoa(aName), razao_social(rs), nome_fantasia(nf)
{
    setCNPJ(aCnpj);
}

PessoaJuridica &PessoaJuridica::setCNPJ(string new_cnpj) {
    if (new_cnpj.size() != 18 || !count_digits(new_cnpj) || !count_dots(new_cnpj) || !count_hairline(new_cnpj) ||
            !count_dash(new_cnpj))
        this->cnpj = "XX.XXX.XXX/0001-XX";
    else
        this->cnpj = new_cnpj;
    return *this;
}

PessoaJuridica &PessoaJuridica::setRazao_social(string new_razao_social) {
    this->razao_social = new_razao_social;
    return *this;
}

PessoaJuridica &PessoaJuridica::setNome_fantasia(string new_nome_fantasia) {
    this->nome_fantasia = new_nome_fantasia;
    return *this;
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

PessoaJuridica::PessoaJuridica() {

}

