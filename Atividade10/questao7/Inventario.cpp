//
// Created by luis on 09/09/2021.
//

#include "Inventario.h"

#include <iostream>
using std::cout, std::endl;

#include <iomanip>
using std::setw;

using std::setprecision;

using std::left, std::right;

using std::fixed, std::defaultfloat;

Inventario::Inventario(fstream &f) {
//    setUp(f);
}

bool Inventario::setUp(fstream &f) {
    Ferramenta empty;
    f.clear();
    f.seekp(0);
    for (int i = 0; i < 100; i++)
        f.write(reinterpret_cast<char *> (&empty), sizeof(Ferramenta));
    f.flush();
    return true;
}

Inventario::~Inventario() {
}

bool Inventario::salvarDados(Ferramenta *ferramentas, int qtFerramentas, fstream &f) {
    f.clear();
    int position;
    for (int i = 0; i < qtFerramentas; i++) {
        position = ferramentas[i].getNumRegistro();
        f.seekp(position * sizeof(ferramentas[i]));
        f.write(reinterpret_cast<char *> (&ferramentas[i]), sizeof(ferramentas[i]));
    }
    f.flush();
    this->quantidade = qtFerramentas;
    return true;
}

bool Inventario::adicionarFerramenta(fstream &f, Ferramenta& novaFerramenta) {
    f.clear();
    f.seekp(novaFerramenta.getNumRegistro() * sizeof(Ferramenta));
    f.write(reinterpret_cast<char *> (&novaFerramenta), sizeof(Ferramenta));
    f.flush();
    this->quantidade++;
    return true;
}

bool Inventario::listarFerramentas(fstream &f) {
    Ferramenta ferr;
    cout << fixed;
    f.clear();
    f.seekg(0);
    while (true) {
        f.read(reinterpret_cast<char *> (&ferr), sizeof(Ferramenta));
        if (f.eof())
            break;
        if (strcmp(ferr.getNomeFerramenta(), "") == 0)
            continue;

        cout << ferr.getNumRegistro() << ' ' << setw(15) << left << ferr.getNomeFerramenta() << ' ' << setw(8) << right <<
        ferr.getQuantidade() << ' ' << setw(5) << left << setprecision(2) << ferr.getPreco() << endl;
    }
    cout << defaultfloat;
    return true;
}

bool Inventario::excluirFerramenta(int numRegistro, fstream& f) {
    Ferramenta aux;
    f.clear();
    int position = numRegistro * sizeof(Ferramenta);
    f.seekg(position);
    f.read(reinterpret_cast<char *> (&aux), sizeof(Ferramenta));
    aux.setNomeFerramenta("");
    f.seekp(position);
    f.write(reinterpret_cast<char *> (&aux), sizeof(Ferramenta));
    f.flush();
    return true;
}

bool Inventario::atualizarDados(fstream &f, Ferramenta& novaFerramenta) {
    f.clear();
    f.seekp(novaFerramenta.getNumRegistro() * sizeof(Ferramenta));
    f.write(reinterpret_cast<char *> (&novaFerramenta), sizeof(Ferramenta));
    f.flush();
    return true;
}






