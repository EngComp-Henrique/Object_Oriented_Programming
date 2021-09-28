//
// Created by luis on 02/09/2021.
//

#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include <string>
using std::string;

#include "Pessoa.h"

class PessoaFisica: public Pessoa {
private:
    string cpf;
    string estadoCivil;
    string data_nasc;
    bool count_digits(string);
    bool  count_dots(string);
    bool count_hairline(string);
public:
    PessoaFisica(string, string, string, string, string, string);
    ~PessoaFisica() {};
    string getNasc() const {return data_nasc;}
    string getEstCivil() const {return estadoCivil;}
    PessoaFisica& setCpf(string);
    virtual string getCpfOuCnpj() const {return cpf;}
    virtual void verContato() const;
};


#endif
