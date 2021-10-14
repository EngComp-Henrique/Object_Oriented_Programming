#include "../include/PessoaJuridica.h"

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

PessoaJuridica::PessoaJuridica(string nm, string address, string phone, string email, string newCNPJ, string newTN) :
Pessoa(nm, address, phone, email) 
{
    setCNPJ(newCNPJ);
    setTradeName(newTN);
}

PessoaJuridica& PessoaJuridica::setCNPJ(string new_cnpj) 
{
    if (new_cnpj.size() != 14 || !count_digits_cnpj(new_cnpj))
        throw WrongDataError();
    else
        this->cnpj = new_cnpj;
    return *this;
}

PessoaJuridica& PessoaJuridica::setTradeName(string trName) 
{
    this->tradeName = trName;
    return *this;
}

bool PessoaJuridica::count_digits_cnpj(string new_cnpj) {
    int count = 0;
    for (auto i: new_cnpj) {
        if (isdigit(i))
            count++;
    }
    if (count == 14)
        return true;
    throw WrongDataError();
}

void PessoaJuridica::getInfoAccount() const
{
    cout << sep_pj << endl;
    cout << "Nome empresarial:" << left << setfill('.') << setw(3) << " " << getTradeName() << endl;
    cout << "Nome fantasia:" << left << setfill('.') << setw(6) << " " << getName() << endl;
    cout << "CNPJ:" << left << setfill('.') << setw(15) << " " << cnpj << endl;
    cout << "Endereço:" << left << setfill('.') << setw(11) << " " << getAddress() << endl;
    cout << "Número de celular:" << left << setfill('.') << setw(2) << " " << getPhone() << endl;
    cout << "Email:" << left << setfill('.') << setw(14) << " " << getEmail() << endl;
    cout << sep_pj << endl;
}
