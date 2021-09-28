//
// Created by luis on 02/09/2021.
//

#ifndef AGENDA_PESSOAJURIDICA_H
#define AGENDA_PESSOAJURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica: public Pessoa {
private:
    string cnpj;
    string insc_social;
    string razao_social;
    bool count_digits(string);
    bool  count_dots(string);
    bool count_hairline(string);
    bool count_dash(string);
public:
    PessoaJuridica(string, string, string, string, string, string);
    ~PessoaJuridica() { };
    PessoaJuridica& setCNPJ(string);
    PessoaJuridica& setRazao_social(string);
    PessoaJuridica& setInsc_social(string);
    string getInsc_social() const {return insc_social;}
    string getRazao_social() const {return razao_social;}
    virtual string getCpfOuCnpj() const {return cnpj;}
    virtual void verContato() const;
};


#endif //AGENDA_PESSOAJURIDICA_H
