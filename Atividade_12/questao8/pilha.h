#ifndef PILHA_H
#define PILHA_H 

#include <iostream> 
using std::ostream;
using std::endl;

#include "pilha_cheia_error.h"

#include "pilha_vazia_error.h"

template < class T >
class Pilha 
{
    //função friend amiga apenas do correspondente
    friend ostream &operator<<(ostream &out, const Pilha<T> &obj)
    {
        out << "[" << endl;
        for (int i = obj.pos - 1 ; i >= 0 ; i--)
        out << " " << obj.pPtr[i] << endl;
        out << "]";
        return out;
    }
public:
    Pilha( int = 10 );
    ~Pilha();

    bool push(const T &);
    bool pop(T &);

    int isEmpty() const { return pos == 0; }
    int isFull() const { return pos == tam; }

private:
    T *pPtr;
    int pos, tam;
};

template < class T >
Pilha<T>::Pilha( int tam )
{
    this->tam = ( (tam > 0) ? tam : 10 );
    pos = 0;

    pPtr = new T[this->tam];
}

template < class T >
Pilha<T>::~Pilha()
{
    delete [] pPtr;
}

template < class T >
bool Pilha<T>::push(const T &el)
{
    if (!isFull()) {
        pPtr[pos++] = el;
        return true;
    }
    throw PilhaCheia();
    return false;
}

template < class T>
bool Pilha<T>::pop(T &el)
{
    if (!isEmpty()) {
        el = pPtr[--pos];
        return true;
    }
    throw PilhaVazia();
    return false;
}

#endif