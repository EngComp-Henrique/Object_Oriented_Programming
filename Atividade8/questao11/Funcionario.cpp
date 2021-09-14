//
// Created by luis on 26/08/2021.
//

#include "Funcionario.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

#include <iostream>
using std::endl;

ostream& operator<<(ostream& out, const Funcionario& func) {
    out << "Nome: " << func.name << endl;
    out << "CPF: " << func.getCpf() << endl;
    out << "Matrícula: " << func.getRegistry() << endl;
    out << "Salário base (US$): " << func.getBaseSalary() << endl;
    out << "Carga horária mensal (em horas): " << func.getMonthlyHours() << endl;
    out << "Horas trabalhadas: " << func.getWorkingHours() << endl;
    out << "Salário bruto (US$): " << func.grossWageCalculation() << endl;
    return out;
}

Funcionario::Funcionario(string aName, string aCpf, string reg, float bs, int mh, int wh) : PessoaFisica(aName, aCpf), registry(reg) {
    setBaseSalary(bs);
    setMonthlyHours(mh);
    setWorkingHours(wh);
}

Funcionario &Funcionario::setRegistry(string newRegistry) {
    this->registry = newRegistry;
    return *this;
}

Funcionario &Funcionario::setBaseSalary(float newBaseSalary) {
    if (newBaseSalary > 0.0)
        this->baseSalary = newBaseSalary;
    else
        this->baseSalary = 0.0;
    return *this;
}

Funcionario &Funcionario::setMonthlyHours(int newMonthlyHours) {
    this->monthlyHours = (newMonthlyHours > 0) ? newMonthlyHours : 0;
    return *this;
}

Funcionario &Funcionario::setWorkingHours(int newWorkingHours) {
    if ((newWorkingHours >= 0) && (newWorkingHours < getMonthlyHours()))
        this->workingkHours = newWorkingHours;
    else if (newWorkingHours < 0)
        this->workingkHours = 0;
    else
        this->workingkHours = newWorkingHours - getMonthlyHours();
    return *this;
}

Funcionario::Funcionario() {

}
