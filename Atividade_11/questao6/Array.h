#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream, std::istream;

using std::cerr;



template<class T = int, int TAM = 10>

class Array
{
    // cout << obj
    friend ostream &operator<<(ostream& out, const Array<T, TAM>a) {
        for (int i = 0 ; i < a.tam ; i++)
            out << a.arr[i] << " ";
        out << endl;
        return out;
    }

    // cin >> obj
    friend istream &operator>>(istream &inp, const Array<T, TAM> &a) {
        for (int i = 0 ; i < a.tam ; i++)
            inp >> a.arr[i];
        return inp;
    }

public:
    Array();    //construtor-padrão
    Array(const Array<T, TAM> &); //construtor de cópia
    ~Array();             //destrutor

    int getSize() const;


    Array<T, TAM> operator+(const Array &) const; // Duvida
    const Array<T, TAM> &operator+=(const Array<T, TAM> &);

    const Array<T, TAM> &operator=( const Array<T, TAM> & ); //operador atribuição. "const Array &" evita algo como (a = b) = c

    bool operator==( const Array<T, TAM> & ) const; //operador de igualdade

    bool operator!=( const Array<T, TAM> &dir) const
    {
        return !(*this == dir);
    }

    int &operator[](int); //permite modificar o elemento
    int operator[](int) const; //não permite modificar o elemento

private:
    int tam;
    T *arr;
};

template <class T, int TAM>
Array<T, TAM>::Array() {
    this->tam = (TAM > 0 ? TAM : 10);
    arr = new T[this->tam];
}

template <class T, int TAM>
Array<T, TAM>::Array(const Array<T, TAM> &obj) : tam(obj.tam) {
    arr = new T[this->tam];

    for (int i = 0 ; i < this->tam ; i++)
        arr[i] = obj.arr[i];
}

template <class T, int TAM>
Array<T, TAM>::~Array<T, TAM>() {
    delete [] arr;
}

template <class T, int TAM>
int Array<T, TAM>::getSize() const { return tam;}

template <class T, int TAM>
const Array<T, TAM>& Array<T, TAM>::operator=(const Array<T, TAM> &obj) {
    if (&obj != this) // evita auto-atribuição
    {
        if (this->tam != obj.tam)
        {
            delete [] this->arr;
            this->tam = obj.tam;
            this->arr = new T[this->tam];
        }

        for (int i = 0 ; i < this->tam ; i++)
            arr[i] = obj.arr[i];

    }
    return *this;
}

template <class T, int TAM>
bool Array<T, TAM>::operator==(const Array<T, TAM> &obj) const {
    if (this->tam != obj.tam)
        return false;

    for (int i = 0 ; i < this->tam ; i++)
        if (arr[i] != obj.arr[i])
            return false;

    return true;
}

template <class T, int TAM>
int &Array<T, TAM>::operator[](int i) {
    if (i < 0 || i >= tam)
    {
        cerr << "Erro: Indice " << i << " fora de faixa." << endl;

        exit(1);
    }

    return arr[i];
}

template <class T, int TAM>
int Array<T, TAM>::operator[](int i) const {
    if (i < 0 || i >= tam)
    {
        cerr << "Erro: Indice " << i << " fora de faixa." << endl;

        exit(1);
    }

    return arr[i];
}

template <class T, int TAM>
Array<T, TAM> Array<T, TAM>::operator+(const Array<T, TAM> &newArr) const {
    Array concat(this->getSize() + newArr.getSize());
    for (int i = 0; i < this->tam; i++) {
        concat[i] = this->arr[i];
    }
    for (int i = this->tam, j = 0; j < newArr.tam; j++, i++) {
        concat[i] = newArr[j];
    }
    return concat;
}

template <class T, int TAM>
const Array<T, TAM>&Array<T, TAM>::operator+=(const Array<T, TAM> & newArr) {
    Array temp = *this + newArr;
    *this = temp;
    return *this;
}

#endif