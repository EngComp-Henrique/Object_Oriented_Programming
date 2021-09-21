#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "Fila.h"

int main() {
    Fila<string, 3> filaStr;
    filaStr.enqueue("Luis");
    filaStr.enqueue("Matheus");
    filaStr.enqueue("Henrique");

    Fila<int, 8> filaNum;
    filaNum.enqueue(10);
    filaNum.enqueue(20);
    filaNum.enqueue(30);
    filaNum.enqueue(40);
    filaNum.enqueue(50);
    filaNum.enqueue(60);
    filaNum.enqueue(70);
    filaNum.enqueue(80);


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
