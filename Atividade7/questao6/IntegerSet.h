//
// Created by luis on 13/08/2021.
//

#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet {
private:
    int array[100];
public:
    friend IntegerSet operator|(IntegerSet &, IntegerSet &);
    friend IntegerSet operator&(IntegerSet &, IntegerSet &);
    friend IntegerSet &operator<<(IntegerSet &, int);
    friend IntegerSet  &operator>>(IntegerSet &, int);
    IntegerSet(int *, int );
    IntegerSet();
    void setUpArray();
    void insertElement(int);
    void deleteElement(int);
    void print() const;
};


#endif
