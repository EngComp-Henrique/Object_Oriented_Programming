#include <iostream>
using std::cout, std::cin, std::endl;

#include "Inventario.h"

#include <fstream>
using std::fstream, std::ifstream;

#include <string>
using std::string;

int main() {
//    Ferramenta ferramentas[8] {
//            {3, "Lixadeira", 7, 57.98}, {17, "Martelo", 76, 11.99},
//            {24, "Serra tico-tico", 21, 11.00}, {39, "Cortador de grama", 3, 79.50},
//            {56, "Serra elétrica", 18, 99.99}, {68, "Chave de fenda", 106, 6.99},
//            {77, "Marreta", 11, 21.50}, {83, "Chave inglesa", 34, 7.50}
//    };
    fstream fileIO("hardware.dat", std::ios::out | std::ios::in);

    if (!fileIO)
        fileIO.open("hardware.dat", std::ios::out);

    if (!fileIO)
        return 1;

    Inventario caixaDeFerramentas(fileIO);
//    caixaDeFerramentas.salvarDados(ferramentas, 8, fileIO);
    caixaDeFerramentas.listarFerramentas(fileIO);

    Ferramenta novaFerramenta(0, "Machado", 11, 20.99);
    caixaDeFerramentas.adicionarFerramenta(fileIO, novaFerramenta);
    cout << "--------------------------------" << endl;
    caixaDeFerramentas.listarFerramentas(fileIO);

    Ferramenta novaFerramenta2(99, "Maçarico", 2, 25.77);
    caixaDeFerramentas.adicionarFerramenta(fileIO, novaFerramenta2);
    cout << "--------------------------------" << endl;
    caixaDeFerramentas.listarFerramentas(fileIO);

    cout << "--------------------------------" << endl;
    caixaDeFerramentas.excluirFerramenta(24, fileIO);
    caixaDeFerramentas.listarFerramentas(fileIO);

    cout << "--------------------------------" << endl;
    Ferramenta atualizada(56, "Chave Phillips", 10, 10.00);
    caixaDeFerramentas.atualizarDados(fileIO, atualizada);
    caixaDeFerramentas.listarFerramentas(fileIO);
    return 0;
}
