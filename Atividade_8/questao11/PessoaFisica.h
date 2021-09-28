//
// Created by luis on 26/08/2021.
//

#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaFisica: public Pessoa{
private:
    string cpf;
    bool count_digits(string);
    bool  count_dots(string);
    bool count_hairline(string);
public:
    PessoaFisica(string, string);
    PessoaFisica();
    string getCpf() const {return cpf;}
    PessoaFisica& setCpf(string);
};


#endif
