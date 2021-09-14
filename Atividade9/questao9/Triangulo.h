//
// Created by luis on 01/09/2021.
//

#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Triangulo : public FormaBidimensional
{
public:
    Triangulo(float b, float a) : FormaBidimensional(3), base(b), altura(a) {}

    virtual void desenhar() {
        cout << "  .   " << endl;
        cout << " / \\ " << endl;
        cout << "/   \\" << endl;
        cout << "~~~~~ " << endl;
    }
    virtual float calcularArea() const {
        return base * altura;
    }
    virtual float calcularPerimetro() const {
        return base * 3;
    }
private:
    float base, altura;
};

#endif