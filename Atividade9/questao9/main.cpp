#include <iostream>
using std::cout, std::endl;

#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

int main() {
    //FormaBidimensional fd(2); // ERRO!!!!
    char linha[] = "---------------------\n";

    FormaBidimensional *formas[] = {new Quadrado(4), new Circulo(5), new Triangulo(6, 8)};

    for (int i = 0 ; i < 3 ; i++)
    {
        formas[i]->desenhar();
        cout << "Área da figura: " << formas[i]->calcularArea() << endl;
        cout << "Perímetro da figura: " << formas[i]->calcularPerimetro() << endl;
        cout << linha;
        delete formas[i];
    }

    return 0;
}