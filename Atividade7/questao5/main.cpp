#include <iostream>
using std::cout, std::endl;
using std::cin;

#include "Array.h"

int main() {
    Array a1(7);  //array de 7 elementos
    Array a2;     //array de 10 elementos

    cout << "Digite uma sequência de números de tamanho (array a1) " << a1.getSize() << ": ";
    cin >> a1;    //lendo array
    cout << "Array a1: " << a1;   //escrevendo array

    cout << "Digite uma sequência de números de tamanho (array a2) " << a2.getSize() << ": ";
    cin >> a2;
    cout << "Array a2: " << a2;

    if (a1 == a2)
        cout << "a1 e a2 são iguais";
    else
        cout << "a1 e a2 não são iguais" << endl;


    cout << "Criando array a3 a partir de a1" << endl;
    Array a3(a1);

    cout << "Modificando posição 5 do array a3 e verificando se a1 mudou: " << endl;
    a3[5] = 100; //invoca int &operator[](int)
    cout << "Verificando se a2 está intacto: ";
    cout << a2;

    cout << "a3[5] == " << a3[5] << endl;  //int operator[](int) const
    cout << "a1[5] == " << a1[5] << endl;

//    cout << "Atribuindo array a3 ao array a2" << endl;
//    a2 = a3;

    cout << "a2[5] == " << a2[5] << endl;

    Array a4;
    a4 = a1 + a2;
    cout << "Array a4 (a1 + a2): ";
    cout << a4;

    cout << "Verificando se a1 está intacto: ";
    cout << a1;

    cout << "Verificando se a2 está intacto: ";
    cout << a2;

    cout << "Modificando a1" << endl;
    a1 += a2;
    cout << "Array a1: ";
    cout << a1;

    return 0;
}