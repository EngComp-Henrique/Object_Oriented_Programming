#include <iostream>
using std::cout, std::endl;

#include "Complex.h"

int main() {
    Complex num1(10,-1);
    Complex num2(5,3);
    Complex num3;
    Complex num4;

    char linha[] = "--------------------";
    cout << "C1: ";
    cout << num1;
    cout << "C2: ";
    cout << num2;

    num3 = num1 + num2;
    cout << "C3: ";
    cout << num3;

    num4 = num1 - num2;
    cout << "C4: ";
    cout << num4;

    num1 += num2;
    cout << "C1: ";
    cout << num1;

    num1 -= num4;
    cout << "C1: ";
    cout << num1;

    cout << linha << endl;

    num1++;
    ++num2;
    num3--;
    --num4;

    cout << "C1: ";
    cout << num1;
    cout << "C2: ";
    cout << num2;
    cout << "C3: ";
    cout << num3;
    cout << "C4: ";
    cout << num4;

    return 0;
}