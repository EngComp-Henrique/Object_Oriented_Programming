//
// Created by luis on 26/08/2021.
//

#include "Pessoa.h"

#include <string>
#include <iostream>
using std::string, std::endl, std::ostream;

ostream& operator<<(ostream& out, const Pessoa& p) {
    out << "Nome da pessoa: " << p.name << endl;
    return out;
}

Pessoa::Pessoa(string aName): name(aName) {

}

Pessoa& Pessoa::setName(string newName) {
    this->name = newName;
    return *this;
}