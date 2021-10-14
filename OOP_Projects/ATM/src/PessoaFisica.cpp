#include "../include/PessoaFisica.h"

#include <iostream>
using std::cout;
using std::endl;
using std::right;
using std::left;

#include <algorithm>

#include <iomanip>
using std::setfill;
using std::setw;

#include <string>
using std::string;


PessoaFisica::PessoaFisica(string nm, string address, string phone, string email, string newCPF, int y) :
Pessoa(nm, address, phone, email) 
{
    validateCpf(newCPF);
    validateBirth(y);
}

void PessoaFisica::getInfoAccount() const
{
    time_t t;
    struct tm* info;
    time(&t);
    cout << sep_pf << endl;
    info = localtime(&t);
    cout << "Nome:" << left << setfill('.') << setw(15) << " " << getName() << endl;
    cout << "CPF:"  << left << setfill('.')  << setw(16) << " " << getCPF() << endl;
    cout << "Idade do titular:"  << left << setfill('.') << setw(3) << " " << (info->tm_year + 1900 - getByear()) << endl;
    cout << "Endereço:" << left << setfill('.') << setw(11) << " " << getAddress() << endl;
    cout << "Número de celular:" << left << setfill('.') << setw(2) << " " << getPhone() << endl;
    cout << "Email:" << left << setfill('.') << setw(14) << " " << getEmail() << endl;
    cout << sep_pf << endl;
}

PessoaFisica& PessoaFisica::validateCpf(string newCpf) 
{
    if (newCpf.size() != 11 || !count_digits_cpf(newCpf))
        throw WrongDataError();
    else
        this->cpf = newCpf;
    return *this;
}

PessoaFisica& PessoaFisica::validateBirth(int y) 
{
    this->Byear = (y >= 1900 && y <= 2100) ? y : 1900;
    return *this;
}

bool PessoaFisica::count_digits_cpf(string cpf_analisado) {
    int count = 0;
    for (auto s: cpf_analisado) {
        if (isdigit(s))
            count++;
    }
    if (count == 11)
        return true;
    throw WrongDataError();
}

