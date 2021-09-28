//
// Created by luis on 26/08/2021.
//

#ifndef HERANCA_PESSOA_H
#define HERANCA_PESSOA_H

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class Pessoa{
    friend ostream& operator<<(ostream&, const Pessoa&);
protected:
    string name;
public:
    Pessoa(string);
    Pessoa& setName(string);
};

#endif
