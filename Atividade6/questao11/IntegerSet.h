//
// Created by luis on 13/08/2021.
//

#ifndef INTEGERSET_H
#define INTEGERSET_H


class IntegerSet {
private:
    int array[100];
public:
    friend IntegerSet unionOfSets(IntegerSet &, IntegerSet &);
    friend IntegerSet intersectionOfSets(IntegerSet &, IntegerSet &);
    IntegerSet(int *, int );
    IntegerSet();
    void setUpArray();
    void insertElement(int);
    void deleteElement(int);
    void print() const;
};


#endif
