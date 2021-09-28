//
// Created by luis on 11/08/2021.
//

#include "Agenda.h"
#include <iostream>
using std::cout, std::endl;

int Agenda::qt_pessoas = 0;

void Agenda::armazenaPessoa(string nome, int idade, float altura) {
    armazenaPessoa(Pessoa(nome, idade, altura));
}

void Agenda::armazenaPessoa(const Pessoa &p) {
    if (qt_pessoas < 10) {
        pessoas[qt_pessoas] = p;
        qt_pessoas++;
    }
    else
        cout << "Agenda já está lotada!" << endl;
}

void Agenda::removePessoa(string nome) {
    if (qt_pessoas == 0) {
        cout << "Não há pessoas para remover!" << endl;
    } else {
        int pessoa_index = buscaPessoa(nome) - 1;
        for (int i = pessoa_index; i < qt_pessoas - 1; i++) {
            Pessoa aux = pessoas[i];
            pessoas[i] = pessoas[i + 1];
            pessoas[i + 1] = aux;
        }
        qt_pessoas--;
    }
}

int Agenda::buscaPessoa(string nome) const {
    for (int i = 0; i < qt_pessoas; i++) {
        if (pessoas[i].getName() == nome) {
            return i + 1;
        }
    }
    return 0;
}

void Agenda::imprimePovo() const {
    if (qt_pessoas == 0) {
        cout << "Não há pessoas para exibir!" << endl;
    } else {
        cout << "Pessoas cadastradas:" << endl << endl;
        for (int i = 0; i < qt_pessoas; i++) {
            cout << "Pessoa número " << i + 1 << endl;
            pessoas[i].getInfo();
        }
    }
}

void Agenda::imprimePessoa(int i) const {
    pessoas[i - 1].getInfo();
}
