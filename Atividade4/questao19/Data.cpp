//
// Created by luis on 29/07/2021.
//

#include "Data.h"
#include <iostream>

Data::Data(int dia, int mes, int ano) {
    setDia(dia);
    setMes(mes);
    setAno(ano);
}

void Data::setDia(int novoDia) {
    if (novoDia <= 0 || novoDia >= 32)
        dia = 1;
    else
        dia = novoDia;
}

void Data::setMes(int novoMes) {
    if (novoMes <= 0 || novoMes >= 12)
        mes = 1;
    else
        mes = novoMes;
}

void Data::setAno(int novoAno) {
    if (novoAno <= 0)
        ano = 2021;
    else
        ano = novoAno;
}

int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}

void Data::mostrarData() {
    std::cout << "Data inserida no formato DD/MM/AAAA: " << dia << "/" << mes << "/" << ano << std::endl;
}