//
// Created by luis on 26/08/2021.
//

#ifndef EMPRESA_H
#define EMPRESA_H

#include "PessoaJuridica.h"
#include "Cliente.h"
#include "Funcionario.h"

#include <string>
using std::string;

class Empresa: public PessoaJuridica {
private:
    Funcionario* func_list;
    Cliente* clt_list;
    static int qt_func;
    static int qt_clt;
public:
    Empresa(string, string, string, string);
    Empresa();
    ~Empresa();
    void addFunc(const Funcionario&);
    void addClt(const Cliente&);
    void viewClients() const;
    void viewFunc() const;
    float calcularFolhaDePagamento() const;
};


#endif
