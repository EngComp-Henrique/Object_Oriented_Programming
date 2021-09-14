//
// Created by luis on 02/09/2021.
//

#ifndef CONTATOS_H
#define CONTATOS_H

#include "Pessoa.h"

#include <vector>
using std::vector;

class Contatos {
private:
    vector<const Pessoa*> agenda;
public:
    Contatos() {};
    ~Contatos(){};
    void addContato(const Pessoa&);
    bool delContato(string);
    bool buscarContato(string);
    void exibirAgenda() const;
};


#endif
