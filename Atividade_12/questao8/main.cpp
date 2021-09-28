#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "pilha.h"

#include <stdexcept>
using std::out_of_range;

int main() {
    Pilha<int>pi(3);
    
    int popValue;

    try {
        pi.pop(popValue);
    } catch (out_of_range &e) {
        cerr << "Erro! " << e.what() << endl;
        pi.push(10);
        pi.push(20);
    }

    try {
        cout << pi;
        pi.push(40);
        pi.push(50);
    } catch (out_of_range &e) {
        cerr << "Erro! " << e.what() << endl;
        cerr << pi;
    }
    return 0;
}