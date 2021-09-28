#include <iostream>
#include "retangulo.h"
using std::cout, std::endl;

int main() {
    retangulo r1(25.6, 21);
    retangulo r2(10.5);
    retangulo r3;
    retangulo r4(15, 20);

    cout << "Altura do retângulo 1 (m): " << r1.getHeight() << endl;
    cout << "Comprimento do retângulo 1 (m): " << r1.getWidth() << endl;
    r1.displayPerimeter();
    r1.displayArea();

    cout << endl;

    cout << "Altura do retângulo 2 (m): " << r2.getHeight() << endl;
    cout << "Comprimento do retângulo 2 (m): " << r2.getWidth() << endl;
    r2.displayPerimeter();
    r2.displayArea();

    cout << endl;

    cout << "Altura do retângulo 3 (m): " << r3.getHeight() << endl;
    cout << "Comprimento do retângulo 3 (m): " << r3.getWidth() << endl;
    r3.displayPerimeter();
    r3.displayArea();

    cout << endl;

    cout << "Altura do retângulo 4 (m): " << r4.getHeight() << endl;
    cout << "Comprimento do retângulo 4 (m): " << r4.getWidth() << endl;
    r4.displayPerimeter();
    r4.displayArea();

    return 0;
}
