//
// Created by luis on 28/07/2021.
//

#ifndef CARRO_H
#define CARRO_H

#include <string>
using std::string;

class Carro {
public:
    Carro(string nome, int ano = 0);

    void setMarca(string nome);

    void setAno(int ano);

    string getMarca();

    int getAno();

    void displayMessage();

private:
    string marca;
    int anoCarro;
};

#endif
