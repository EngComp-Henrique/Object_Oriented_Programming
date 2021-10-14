#ifndef PESSOAjURIDICA_H
#define PESSOAjURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica: public Pessoa
{
private:
    string cnpj;
    string tradeName;
    bool count_digits_cnpj(string);
    PessoaJuridica& setCNPJ(string);
    const char* sep_pj = (const char*) "*************************************************************";
public:
    PessoaJuridica(string, string, string, string, string, string);
    ~PessoaJuridica() {};
    PessoaJuridica& setTradeName(string);
    string getCNPJ() const {return cnpj;}
    string getTradeName() const {return tradeName;}
    virtual void getInfoAccount() const;
};

#endif