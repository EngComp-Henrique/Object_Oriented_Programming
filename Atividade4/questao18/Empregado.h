//
// Created by luis on 28/07/2021.
//

#ifndef EMPREGADO_H
#define EMPREGADO_H
#include <string>
using std::string;

class Empregado {
private:
    string nome;
    string sobrenome;
    double salarioMensal;
public:
    Empregado(string nome, string sobrenome, double salario);
    void setNome(string novoNome);
    void setSobrenome(string novoSobrenome);
    void setSalario(double novoSalario);
    string getNome();
    string getSobrenome();
    double getSalario();
    void obterInfo();
};


#endif
