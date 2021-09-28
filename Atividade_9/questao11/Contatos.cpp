//
// Created by luis on 02/09/2021.
//

#include "Contatos.h"

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

void Contatos::addContato(const Pessoa &p) {
    agenda.push_back(&p);
}

bool Contatos::buscarContato(string info) {
    for (auto a: agenda) {
        if ((a->getCpfOuCnpj() == info) || (a->getNome() == info)) {
            cout << "Contato encontrado" << endl;
            a->verContato();
            return true;
        }
    }
    cout << "Contato " << info << " inexistente" << endl;
    return false;
}

bool Contatos::delContato(string info) {
    int i = 0;
    bool encontrou = false;
    for (auto & a: agenda) {
        if ((info == a->getNome()) || (info == a->getCpfOuCnpj())) {
            encontrou = true;
            break;
        }
        i++;
    }
    if (encontrou) {
        for (int j = i; j < agenda.size() - 1; j++) {
            auto aux = agenda[j];
            agenda[j] = agenda[j + 1];
            agenda[j + 1] = aux;
        }
        agenda.pop_back();
        return true;
    }
    return false;
}

void Contatos::exibirAgenda() const {
    char sep[] = "-------------------------------\n";
    for (auto &a: agenda) {
        a->verContato();
        cout << sep;
    }
}


