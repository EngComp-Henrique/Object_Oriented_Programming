//
// Created by luis on 01/09/2021.
//

#ifndef FORMABI_H
#define FORMABI_H

//classe abstrata

class FormaBidimensional
{
public:
    FormaBidimensional(int numLados) : numLados(numLados) { }

    //método virtual puro
    virtual void desenhar() = 0;
    virtual float calcularArea() const = 0;
    virtual float calcularPerimetro() const = 0;
private:
    int numLados;
};

#endif
