#include <iostream>
#include "Pessoa.h"

int main() {
    Pessoa pessoa1("Luis", 18, 180);
    Pessoa pessoa2("Henrique", -12, 306);
    Pessoa pessoa3("", 24, 160);

    pessoa1.getInfo();
    pessoa2.getInfo();
    pessoa3.getInfo();

    pessoa3.setName("João").getInfo();
    pessoa2.setAge(12).getInfo();
    pessoa1.setHeight(178).getInfo();

    return 0;
}
