#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

//o uso de métodos inline não alteram a lógica do programa

int main() {
    Time t(16, 40);
    Time t2;
    Time t3(20);

    t.printUniversal();
    t2.printUniversal();
    t3.printUniversal();

    return 0;
}