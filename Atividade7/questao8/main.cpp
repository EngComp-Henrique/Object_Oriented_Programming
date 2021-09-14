#include <iostream>
#include "HugerInteger.h"

using std::cout, std::endl;

int main() {
    HugerInteger n1, n2, n3, n4, n5, n6, n7;

    n1= "9";
    n2 = "1";
    n3 = "9123456798";
    n4 = "99";
    n5 = "1";
    n6 = "123abc";
    n7 = "9123456797";

    cout << n1;
    cout << n2;
    cout << n3;
    cout << n4;
    cout << n5;
    cout << n6;
    cout << n7;

    cout << endl;

    // Comparação de valores
    if (n1 == n2)
        cout << "n1 é igual a n2" << endl;
    else
        cout << "n1 é diferente de n2" << endl; // Resposta esperada

    if (n1 != n3)
        cout << "n1 é diferente de n3" << endl; // Resposta esperada
    else
        cout << "n1 é igual a n3" << endl;

    if (n2 == n5)
        cout << "n2 é igual a n5" << endl; // Resposta esperada
    else
        cout << "n2 é diferente de n5" << endl;

    if (n1 > n6)
        cout << "n1 é maior que n6" << endl; // Resposta esperada
    else
        cout << "n1 é menor ou igual a n6" << endl;

    if (n3 >= n7)
        cout << "n3 é maior ou igual a n7" << endl; // Resposta esperada
    else
        cout << "n3 é menor que n7" << endl;

    if (n2 <= n5)
        cout << "n2 é menor ou igual a n5" << endl;
    else
        cout << "n5 é maior ou igual a n2" << endl; // Resposta esperada

    cout << endl;

    // Somas
    HugerInteger sum1, sum2, sum3, sum4;
    sum1 = n4 + n2; // 100
    sum2 = n1 + n2; // 10
    sum3 = n2 + n5; // 2
    sum4 = n3 + n2; // 9123456799

    // Resultados das somas
    cout << sum1;
    cout << sum2;
    cout << sum3;
    cout << sum4;

    cout << endl;

    // Objeto somados alteriormente permancem
    cout << n1;
    cout << n2;
    cout << n3;
    cout << n4;
    cout << n5;

    cout << endl;

    // Modificando valores de n1, n2, n3
    n1 += n2;
    n2 += n3;
    n6 += n4;
    n3 += n1;

    cout << n1; // 10
    cout << n2; // 9123456799
    cout << n3; // 9123456808
    cout << n6; // 99;
    return 0;
}
