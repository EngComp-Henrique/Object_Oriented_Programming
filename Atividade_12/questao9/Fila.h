//
// Created by luis on 15/09/2021.
//

#ifndef FILA_H
#define FILA_H

#include <iostream>
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include "fila_vazia_error.h"

#include "fila_cheia_error.h"

template < class T = int , int TAM = 10>
class Fila{
    friend ostream &operator<<(ostream& out, const Fila<T, TAM>f) {
        for (int i = 0 ; i < f.tamanho; i++) {
            if (i < f.tamanho - 1) { out << f.fila[i] << "<-"; }
            else
                out << f.fila[i];
        }
        out << endl;
        return out;
    }

private:
    T fila[TAM];
    int tamanho;
public:
    Fila();
    bool enqueue(const T&);
    bool dequeue();
    bool isEmpty() {return tamanho == 0;}
    bool isFull() {return tamanho == TAM;}
    void peek();

};

template <class T, int TAM>
Fila<T, TAM>::Fila() {
    tamanho = 0;
}

template <class T, int TAM>
bool Fila<T, TAM>::dequeue() {
    if (!isEmpty()) {
        for (int i = 1; i < tamanho; i++) {
            fila[i - 1] = fila[i];
        }
        tamanho--;
        return true;
    }
    throw FilaVazia();
    return false;
}

template <class T, int TAM>
bool Fila<T, TAM>::enqueue(const T &element) {
    if (!isFull()) {
        fila[tamanho++] = element;
        return true;
    }
    throw FilaCheia();
    return false;
}

template <class T, int TAM>
void Fila<T, TAM>::peek() {
    if (!isEmpty()) {
        cout << fila[0] << endl;
        return;
    }
    throw FilaVazia();
}

#endif
