//
// Created by luis on 26/08/2021.
//

#include "Empresa.h"
#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

int Empresa::qt_clt = 0;
int Empresa::qt_func = 0;


Empresa::Empresa(string name, string cnpj, string rs, string nf) : PessoaJuridica(name, cnpj, rs, nf) {
    clt_list = new Cliente[10];
    func_list = new Funcionario[10];
}

Empresa::~Empresa() {
    delete [] clt_list;
    delete [] func_list;
}

void Empresa::addFunc(const Funcionario &f) {
    if (qt_func < 10) {
        func_list[qt_func] = f;
        qt_func++;
    }
    else
        cout << "Lista de funcionários cheia!" << endl;
}

void Empresa::addClt(const Cliente &c) {
    if (qt_clt < 10) {
        clt_list[qt_clt] = c;
        qt_clt++;
    } else
        cout << "Lista de clientes já está cheia!" << endl;
}

void Empresa::viewClients() const {
    cout << "Informações dos clientes:" << endl;
    for (int i = 0; i < qt_clt; i++) {
        cout << clt_list[i];
        cout << endl;
    }
}

void Empresa::viewFunc() const {
    cout << "Informações dos funcionários:" << endl;
    for (int i = 0; i < qt_func; i++) {
        cout << func_list[i];
        cout << endl;
    }
}

float Empresa::calcularFolhaDePagamento() const {
    float total = 0;
    for (int i = 0; i < qt_func; i++) {
        total += func_list[i].grossWageCalculation();
    }
    return total;
}

Empresa::Empresa() {

}



