//
// Created by luis on 01/09/2021.
//

#ifndef TRANSACOES_H
#define TRANSACOES_H

#include <string>
using std::string;

class Transacoes {
private:
    int dia, mes, ano;
    string desc;
    float valor;
public:
    Transacoes(int d, int m, int a, string des, float v) : dia(d), mes(m), ano(a), desc(des), valor(v) { };
    Transacoes() { };
    int getDia() const {return dia;}
    int getMes() const {return mes;}
    int getAno() const {return ano;}
    string getDesc() const {return desc;}
    float getValor() const {return valor;}
};


#endif
