#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "Fila.h"

#include <stdexcept>
using std::out_of_range;

int main() {
    Fila<string, 3> filaStr;

    try {
        filaStr.dequeue();
    } catch(out_of_range &e) {
        cerr << "Erro! " << e.what() << endl;
        filaStr.enqueue("Luis");
        filaStr.enqueue("Matheus");
        filaStr.enqueue("Henrique");
    }

    Fila<int, 8> filaNum;
    try {
        filaNum.enqueue(10);
        filaNum.enqueue(20);
        filaNum.enqueue(30);
        filaNum.enqueue(40);
        filaNum.enqueue(50);
        filaNum.enqueue(60);
        filaNum.enqueue(70);
        filaNum.enqueue(80);
        filaNum.enqueue(90);
    } catch(out_of_range &e) {
        cerr << "Erro! " << e.what() << endl;
    }

    cout << filaStr;
    cout << filaNum;

    filaStr.dequeue();
    filaNum.dequeue();

    cout << filaStr;
    cout << filaNum;

    filaNum.peek();
    filaStr.peek();

    return 0;
}
