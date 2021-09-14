#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

//o uso de métodos inline não alteram a lógica do programa

int main() {
    Time t(16,40);
    Time t2(11, 50, 59);
    Time t3(11, 59, 59);
    Time t4(11, 58, 59);
    Time t5(23, 59, 59);

    t.printUniversal();
    t2.printUniversal();
    t3.printUniversal();
    t4.printUniversal();
    t5.printUniversal();

    cout << endl;

    t.tick();
    t2.tick();
    t3.tick();
    t4.tick();
    t5.tick();

    t.printUniversal();
    t2.printUniversal();
    t3.printUniversal();
    t4.printUniversal();
    t5.printUniversal();

    return 0;
}