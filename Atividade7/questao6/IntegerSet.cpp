//
// Created by luis on 13/08/2021.
//

#include "IntegerSet.h"
#include <iostream>

using std::cout, std::endl;

IntegerSet &operator<<(IntegerSet &set, int value) {
    if (value >= 0 && value <= 99)
        set.insertElement(value);
    return set;
}

IntegerSet &operator>>(IntegerSet &set, int value) {
    if (value >= 0 && value <= 99)
        set.deleteElement(value);
    return set;
}


IntegerSet operator|(IntegerSet &firstSet, IntegerSet &secondSet) {
    IntegerSet merge;
    for (int i = 0; i < 100; i++) {
        if (firstSet.array[i] == 1 || secondSet.array[i] == 1)
            merge.insertElement(i);
    }
    return merge;
}

IntegerSet operator&(IntegerSet &firstSet, IntegerSet &secondSet) {
    IntegerSet inner;
    for (int i = 0; i < 100; i++) {
        if (firstSet.array[i] == 1 && secondSet.array[i] == 1)
            inner.insertElement(i);
    }
    return inner;
}

IntegerSet::IntegerSet(int *arr, int size) {
    setUpArray();
    for (int i = 0; i < size; i++) {
        int v = arr[i];
        array[v] = 1;
    }
}

IntegerSet::IntegerSet() {
    setUpArray();
}

void IntegerSet::setUpArray() {
    for (int i = 0; i < 100; i++) {
        array[i] = 0;
    }
}

void IntegerSet::insertElement(int k) {
    array[k] = 1;
}

void IntegerSet::deleteElement(int k) {
    array[k] = 0;
}

void IntegerSet::print() const {
    for (int i = 0; i < 100; i++) {
        if (array[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}