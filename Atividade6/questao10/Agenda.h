//
// Created by luis on 11/08/2021.
//

#ifndef AGENDA_H
#define AGENDA_H
#include "Pessoa.h"
#include <string>
#include <vector>
using std::string;

class Agenda{
public:
    Agenda(int tPessoas = 1);
    ~Agenda();
    void armazenaPessoa(string nome, int idade, float altura);
    void armazenaPessoa(const Pessoa &p);

    void removePessoa(string nome);

    int buscaPessoa(string nome) const; // informa em que posição da agenda está a pessoa
    void imprimePovo() const; // imprime todos os dados de todas as pessoas da agenda
    void imprimePessoa(int i) const; // imprime os dados da pessoa que está na posição 'i' da agenda
private:
    Pessoa *pessoas;
    static int qt_pessoas;
    int max_qt_pessoas;
};



#endif
