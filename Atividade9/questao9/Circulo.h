//
// Created by luis on 01/09/2021.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Circulo : public FormaBidimensional
{
public:
    Circulo(float r) : FormaBidimensional(99999), raio(r) {}

    virtual void desenhar() {
        cout << "  _ " << endl;
        cout << "/   \\" << endl;
        cout << "\\   /" << endl;
        cout << "  ~ " << endl;
    }
    virtual float calcularArea() const {
        return pi * (raio * raio);
    }
    virtual float calcularPerimetro() const {
        return 2 * pi * raio;
    }
private:
    float raio;
    const float pi = 3.14;
};

#endif
