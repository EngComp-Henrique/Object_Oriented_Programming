#include <iostream>
using std::cout, std::endl;

#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "Empresa.h"

int main() {
    char line[] = "---------------------------------------\n";
    Empresa ep1("Manoel Carlo", "01.234.567/0002-89", "Manuel\'s LTDA.", "Padaria do Sr. Manuel.");

    Funcionario f1("Luis Santos", "159.753.258-01", "00011", 1500.56, 160, 152);
    Funcionario f2("Henrique Lima", "012.345.678-90", "00012", 2000.45, 160, 80);
    Funcionario f3("Matheus Sancho", "236.214.698-88", "00013", 5000.00, 200, 190);
    Funcionario f4("Mario", "153.624.486-70", "00014", 10000.55, 100, 80);

    Cliente c1("João Barbosa", "486.957.852-90", "98984-5265", "Copacabana");
    Cliente c2("Pedro", "521.658.987-00", "88951-1236", "Bessa");
    Cliente c3("Marcelo", "000.000.123-02", "91254-5214", "Altiplano");
    Cliente c4("Muriel", "111.222.333-44", "98765-1236", "Mangabeira");

    ep1.addFunc(f1);
    ep1.addFunc(f2);
    ep1.addFunc(f3);
    ep1.addFunc(f4);

    ep1.addClt(c1);
    ep1.addClt(c2);
    ep1.addClt(c3);
    ep1.addClt(c4);

    ep1.viewFunc();
    cout << line;

    ep1.viewClients();
    cout << line;

    cout << "Folha de pagamento dos funcionário da empresa " << ep1.getNome_Fantasia() << " em US$: " << ep1.calcularFolhaDePagamento() << endl;
    cout << line;

    return 0;
}
