//
// Created by luis on 26/08/2021.
//

#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica: public Pessoa{
private:
    string cnpj;
    string razao_social;
    string nome_fantasia;
    bool count_digits(string);
    bool  count_dots(string);
    bool count_hairline(string);
    bool count_dash(string);
public:
    PessoaJuridica(string, string, string, string);
    PessoaJuridica();
    string getCNPJ() const {return cnpj;}
    string getRazao_Social() const {return razao_social;}
    string getNome_Fantasia() const {return nome_fantasia;}
    PessoaJuridica& setCNPJ(string);
    PessoaJuridica& setRazao_social(string);
    PessoaJuridica& setNome_fantasia(string);
};


#endif
