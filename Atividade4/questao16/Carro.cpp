//
// Created by luis on 28/07/2021.
//

#include <iostream>
#include "Carro.h"

using std::cout, std::endl;

Carro::Carro(string nome, int ano) {
    setMarca(nome);
    setAno(ano);
}

void Carro::setMarca(string nome) {
    if (nome == "")
        marca = "\"Sem Marca\"";
    else if (nome.length() > 10)
        marca = nome.substr(0, 10);
    else
        marca = nome;
}

void Carro::setAno(int ano = 0) {
    if (ano <= 0 || ano > 2021)
        anoCarro = 2021;
    else
        anoCarro = ano;
}

string Carro::getMarca() {
    return marca;
}

int Carro::getAno() {
    return anoCarro;
}

void Carro::displayMessage() {
    cout << "Olá, eu sou um carro da marca " << getMarca() << endl;
    cout << "Sou do ano de " << getAno() << endl;
}


