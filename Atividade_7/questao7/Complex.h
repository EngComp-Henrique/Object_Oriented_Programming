#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

class Complex
{
    friend ostream &operator<<(ostream &, const Complex &);
public:
    Complex( int a = 0, int b = 0)
    {
        real = a;
        imaginaria = b;
    }
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    const Complex &operator+=(const Complex &);
    const Complex &operator-=(const Complex &);
    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);

private:
    double real;
    double imaginaria;
};

#endif