#include <iostream>
#include "HugerInteger.h"
using std::cout, std::endl;
int main() {
    HugerInteger n1("9"), n2("1"), n3("9123456798"), n4("99"), n5("1");
    HugerInteger n6("123abc"), n7("9123456797");

    n1.output();
    n2.output();
    n3.output();
    n4.output();
    n5.output();
    n6.output();
    n7.output();

    cout << endl;

    // Comparação de valores
    if (n1.isEqual(n2))
        cout << "n1 é igual a n2" << endl;
    else
        cout << "n1 é diferente de n2" << endl;

    if (n1.isNotEqual(n3))
        cout << "n1 é diferente de n3" << endl;
    else
        cout << "n1 é igual a n3" << endl;

    if (n2.isEqual(n5))
        cout << "n2 é igual a n5" << endl;
    else
        cout << "n2 é diferente de n5" << endl;

    if (n1.isGreaterThan(n6))
        cout << "n1 é maior que n6" << endl;
    else
        cout << "n1 é menor ou igual a n6" << endl;

    if (n3.isGreaterThanOrEqual(n7))
        cout << "n3 é maior ou igual a n7" << endl;
    else
        cout << "n3 é menor que n7" << endl;

    if (n2.isLessThanOrEqual(n5))
        cout << "n2 é menor ou igual a n5" << endl;
    else
        cout << "n5 é maior ou igual a n2" << endl;

    cout << endl;

    // Somas
    n4.add(n2);
    n1.add(n2);
    n2.add(n5);
    n3.add(n2);

    // Novos outputs
    n1.output();
    n2.output();
    n3.output();
    n4.output();

    return 0;
}
