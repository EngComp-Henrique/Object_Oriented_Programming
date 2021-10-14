#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Pessoa.h"

#include <string>
using std::string;

#include <ctime>

class PessoaFisica: public Pessoa {
    private:
        string cpf;
        int Byear;
        bool count_digits_cpf(string);
        PessoaFisica& validateBirth(int);
        PessoaFisica& validateCpf(string);
        const char* sep_pf = (const char*) "*************************************************************";
    public:
        PessoaFisica(string, string, string, string,  string, int);
        ~PessoaFisica() {};
        string getCPF() const {return cpf;}
        int getByear() const {return Byear;}
        virtual void getInfoAccount() const;
};


#endif