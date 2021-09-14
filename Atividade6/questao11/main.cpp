#include <iostream>
#include "IntegerSet.h"

using std::cout, std::endl;

IntegerSet unionOfSets(IntegerSet &firstSet, IntegerSet &secondSet) {
    IntegerSet merge;
    for (int i = 0; i < 100; i++) {
        if (firstSet.array[i] == 1 || secondSet.array[i] == 1)
            merge.insertElement(i);
    }
    return merge;
}

IntegerSet intersectionOfSets(IntegerSet &firstSet, IntegerSet &secondSet) {
    IntegerSet inner;
    for (int i = 0; i < 100; i++) {
        if (firstSet.array[i] == 1 && secondSet.array[i] == 1)
            inner.insertElement(i);
    }
    return inner;
}

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

    IntegerSet set3 = unionOfSets(set1, set2);
    IntegerSet set4 = intersectionOfSets(set1, set2);

    cout << "União dos múltiplos de 3 com os múltiplos de 5: \n";
    set3.print();
    cout << "Intersecção dos múltiplos de 3 com os múltiplos de 5: \n";
    set4.print();
    return 0;
}
