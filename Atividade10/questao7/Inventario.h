//
// Created by luis on 09/09/2021.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Ferramenta.h"

#include <iomanip>
using std::setw;

using std::setprecision;

#include <fstream>
using std::fstream;

#include <string.h>

class Inventario {
private:
    bool setUp(fstream &f);
    int quantidade = 0;
public:
    Inventario(fstream &);
    ~Inventario();
    bool salvarDados(Ferramenta[], int, fstream&);
    bool adicionarFerramenta(fstream &, Ferramenta &);
    bool listarFerramentas(fstream&);
    bool excluirFerramenta(int, fstream&);
    bool atualizarDados(fstream&, Ferramenta &);
};


#endif
