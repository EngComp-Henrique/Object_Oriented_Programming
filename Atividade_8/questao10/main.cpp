#include <iostream>
using std::cout, std::endl;

#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Funcionario.h"
#include "Cliente.h"

int main() {
    char line[] = "---------------------------------------\n";
    PessoaJuridica pj1("Manoel Carlo", "01.234.567/0002-89", "Manuel\'s LTDA.", "Padaria do Sr. Manuel.");
    Funcionario f1("Luis Santos", "159.753.258-01", "00011", 1500.56, 40, 36);
    Funcionario f2("Henrique Lima", "012.345.678-90", "00012", 2000.45, 40, 10);

    cout << "DADOS DO DONO DA PADARIA:" << endl;
    cout << pj1;
    cout << "CNPJ: " << pj1.getCNPJ() << endl;
    cout << "Razão social: " << pj1.getRazao_Social() << endl;
    cout << "Nome fantasia: " << pj1.getNome_Fantasia() << endl;
    cout << line;

    cout << "DADOS DOS FUNCIONÁRIOS: " << endl;
    cout << f1 << endl;
    cout << f2;
    cout << line;

    Cliente c1("Matheus", "456.123.789-33", "99857a3321", "Rua Alfonso Gonçalvés");
    Cliente c2("Felipe", "741.852.963-89", "91230-6548", "Av. Marivilha Lago");

    cout << "DADOS DOS CLIENTES: " << endl;
    cout << c1 << endl;
    cout << c2;
    cout << line;

    c1.setPhoneNumber("99857-3321");
    c2.setAddress("Av. Maravilha Lago");

    cout << c1 << endl;
    cout << c2;
    cout << line;

    return 0;
}
