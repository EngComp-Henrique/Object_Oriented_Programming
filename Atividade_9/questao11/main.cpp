#include <iostream>
using std::cout, std::endl;

#include "Contatos.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

int main() {
    char sep[] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Contatos c;

    PessoaFisica pf1("Luis", "Rua João Pereira", "luis@gmail.com", "002.321.698-78", "Solteiro", "02/12/2000");
    PessoaFisica pf2("Henrique", "Rua Raimundo Nonato", "henrique@yahoo.com", "987.654.321-99", "Casado", "12/03/1984");
    PessoaFisica pf3("João", "Av. Batista Rosa", "joao_123@outlook.com", "159.654.874-89", "Casado", "29/02/1990");

    PessoaJuridica pj1("Matheus", "Ipanema", "bigTech@gmail.com", "01.234.567/0002-89", "12-256987-200", "BigTEch LTDA.");
    PessoaJuridica pj2("Manoel Carlo", "Rua Afonso Farias", "manCarlos@bol.com", "12.741.258/0002-74", "12-012365-147", "Manuel\\'s LTDA.");
    PessoaJuridica pj3("Guido", "Rua Pythonistas", "carlosM@gmail.com", "19.843.321/0002-51", "45-566225-365", "Python\'s Foundation");

    c.addContato(pf1);
    c.addContato(pf2);
    c.addContato(pf3);

    c.addContato(pj1);
    c.addContato(pj2);
    c.addContato(pj3);

    c.exibirAgenda();

    cout << endl;

    cout << sep;
    c.buscarContato("002.321.698-78");

    cout << sep;
    c.buscarContato("01.234.567/0002-89");

    cout << sep;
    c.buscarContato("Guido");

    cout << sep;
    c.buscarContato("Magalhães");
    cout << sep;

    c.delContato("Guido");
    c.delContato("002.321.698-78");
    c.delContato("01.234.567/0002-89");

    c.exibirAgenda();

    return 0;
}
