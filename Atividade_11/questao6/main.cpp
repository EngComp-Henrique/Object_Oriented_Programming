#include <iostream>
using std::cout, std::endl;
using std::cin;

#include <string>
using std::string;

#include "Array.h"

int main() {
    Array<int, 7> a1;
    Array<string, 3> a2;
    cout << "Digite 7 valores separados por espaço: ";

    cin >> a1;
    cout << a1;

    cout << "Digite 3 palavras separados por espaço: ";

    cin >> a2;
    cout << a2;

    return 0;
}