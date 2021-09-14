#include <iostream>
#include "IntegerSet.h"

using std::cout, std::endl;

int main() {
    IntegerSet set1;
    for(int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            set1.insertElement(i);
        }
    }

    int arr[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90};
    IntegerSet set2(arr, 19);

    cout << "Conjunto do números múltiplos de 3 no intervalo de 0 a 100:\n";
    set1.print();
    cout << "Conjunto do números múltiplos de 5 no intervalo de 0 a 100: \n";
    set2.print();

    IntegerSet set3 = set1 | set2;
    IntegerSet set4 = set1 & set2;

    cout << "União dos múltiplos de 3 com os múltiplos de 5: \n";
    set3.print();
    cout << "Intersecção dos múltiplos de 3 com os múltiplos de 5: \n";
    set4.print();

    set4 << 99;
    set4.print();
    set4 >> 0;
    set4.print();

    return 0;
}
