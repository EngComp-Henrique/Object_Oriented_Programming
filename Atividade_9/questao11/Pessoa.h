//
// Created by luis on 02/09/2021.
//

#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa {
private:
    string nome, endr, email;
public:
    Pessoa(string nm, string ed, string em) : nome(nm), endr(ed), email(em) {};
    Pessoa() {};
    virtual ~Pessoa() {};
    string getNome() const {return nome;}
    string getEndr() const {return endr;}
    string getEmail() const {return email;}
    virtual string getCpfOuCnpj() const = 0;
    virtual void verContato() const = 0;
};


#endif
