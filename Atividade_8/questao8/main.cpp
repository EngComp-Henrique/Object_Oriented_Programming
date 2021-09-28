#include <iostream>
using std::cout, std::endl;

#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

int main() {
    char line[] = "---------------------------------------\n";
    Pessoa p1("Luis Henrique");
    PessoaFisica p2("Luis Lima", "012.345.678-90");
    PessoaJuridica p3("Henrique Santos", "12.321.456/0001-78", "Big Tech Indústrias Ltda", "BTech");

    cout << p1;
    cout << line;

    cout << p2;
    cout << "CPF: " << p2.getCpf() << endl;
    cout << line;

    cout << p3;
    cout << "CNPJ: " << p3.getCNPJ() << endl;
    cout << "Razão social: " << p3.getRazao_Social() << endl;
    cout << "Nome fantasia: " << p3.getNome_Fantasia() << endl;
    cout << line;

    PessoaFisica p4("Carlos Alberto", "987.654.32122");
    PessoaJuridica p5("Manoel Carlo", "0123456789", "Manuel Indústrias Ltda", "Padaria do seu Manuelll");

    cout << p4;
    cout << "CPF: " << p4.getCpf() << endl;
    cout << line;

    cout << p5;
    cout << "CNPJ: " << p5.getCNPJ() << endl;
    cout << "Razão social: " << p5.getRazao_Social() << endl;
    cout << "Nome fantasia: " << p5.getNome_Fantasia() << endl;
    cout << line;

    p4.setCpf("987.654.321-22");
    p5.setName("Manoel Carlos");
    p5.setCNPJ("01.234.567/0002-89");
    p5.setNome_fantasia("Padaria do Sr. Manuel.");
    p5.setRazao_social("Manuel\'s LTDA.");

    cout << p4;
    cout << "CPF: " << p4.getCpf() << endl;
    cout << line;

    cout << p5;
    cout << "CNPJ: " << p5.getCNPJ() << endl;
    cout << "Razão social: " << p5.getRazao_Social() << endl;
    cout << "Nome fantasia: " << p5.getNome_Fantasia() << endl;
    cout << line;

    return 0;
}
