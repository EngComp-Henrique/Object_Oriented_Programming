//
// Created by luis on 28/07/2021.
//

#include <iostream>
#include "Empregado.h"

using std::string;

Empregado::Empregado(string nome, string sobrenome, double salario) {
    setNome(nome);
    setSobrenome(sobrenome);
    setSalario(salario);
}

void Empregado::setNome(string novoNome) {
    nome = novoNome;
}

void Empregado::setSobrenome(string novoSobrenome) {
    sobrenome = novoSobrenome;
}

void Empregado::setSalario(double novoSalario) {
    if (novoSalario <= 0.00)
        salarioMensal = 0.00;
    else
        salarioMensal = novoSalario;
}

string Empregado::getNome() {
    return nome;
}

string Empregado::getSobrenome() {
    return sobrenome;
}

double Empregado::getSalario() {
    return salarioMensal;
}

void Empregado::obterInfo() {
    std::cout << "Nome completo: " << getNome() << " " << getSobrenome() << std::endl;
    std::cout << "Salário atual (R$/Mês): " << getSalario() << std::endl;
}