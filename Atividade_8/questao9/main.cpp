#include <iostream>
using std::cout, std::endl;

#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Funcionario.h"

int main() {
    char line[] = "---------------------------------------\n";
    PessoaJuridica p1("Manoel Carlo", "01.234.567/0002-89", "Manuel\'s LTDA.", "Padaria do Sr. Manuel.");
    Funcionario p2("Luis Santos", "159.753.258-01", "00011", 1500.56, 40, 36);
    Funcionario p3("Henrique Lima", "012.345.678-90", "00012", 2000.45, 40, 10);

    cout << "DADOS DO DONO DA PADARIA:" << endl;
    cout << p1;
    cout << "CNPJ: " << p1.getCNPJ() << endl;
    cout << "Razão social: " << p1.getRazao_Social() << endl;
    cout << "Nome fantasia: " << p1.getNome_Fantasia() << endl;
    cout << line;

    cout << "DADOS DOS FUNCIONÁRIOS: " << endl;
    cout << p2 << endl;
    cout << p3;
    cout << line;

    p2.setWorkingHours(30);
    p2.setBaseSalary(2500.00);

    p3.setMonthlyHours(60);
    p3.setBaseSalary(1500.56);

    cout << "DADOS DOS FUNCIONÁRIOS: " << endl;
    cout << p2 << endl;
    cout << p3;
    cout << line;

    return 0;
}
