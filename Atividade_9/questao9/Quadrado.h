//
// Created by luis on 01/09/2021.
//

#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Quadrado : public FormaBidimensional
{
public:
    Quadrado(float l) : FormaBidimensional(4), lado(l) {}

    virtual void desenhar() {
        cout << "-----" << endl;
        cout << "|   |" << endl;
        cout << "-----" << endl;
    }
    virtual float calcularArea() const {
        return lado * lado;
    }
    virtual float calcularPerimetro() const {
        return lado * 4;
    }

private:
    float lado;
};

#endif