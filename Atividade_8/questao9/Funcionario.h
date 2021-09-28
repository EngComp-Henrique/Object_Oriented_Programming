//
// Created by luis on 26/08/2021.
//

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "PessoaFisica.h"

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class Funcionario: public PessoaFisica {
    friend ostream& operator<<(ostream&, const Funcionario&);
private:
    string registry;
    float baseSalary;
    int monthlyHours;
    int workingkHours;
public:
    Funcionario(string, string, string, float, int, int);
    string getRegistry() const {return registry;}
    float getBaseSalary() const {return baseSalary;}
    int getMonthlyHours() const {return monthlyHours;}
    int getWorkingHours() const {return workingkHours;}
    float grossWageCalculation() const {return baseSalary * workingkHours / monthlyHours;}
    Funcionario& setRegistry(string);
    Funcionario& setBaseSalary(float);
    Funcionario& setMonthlyHours(int);
    Funcionario& setWorkingHours(int);
};


#endif
