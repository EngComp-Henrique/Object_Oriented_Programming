#include <iostream>
using std::cout, std::endl;

#include "Complex.h"

ostream &operator<<(ostream &out, const Complex &c)
{
    cout << c.real << (c.imaginaria >= 0 ? " +" : " ") << c.imaginaria << "*i" << endl;
    return out;
}

Complex Complex::operator+(const Complex &c) const
{
    Complex newComplex(this->real + c.real, this->imaginaria + c.imaginaria);
    return newComplex;
}

Complex Complex::operator-(const Complex &c) const
{
    Complex newComplex(this->real - c.real, this->imaginaria - c.imaginaria);
    return newComplex;
}

const Complex &Complex::operator+=(const Complex &c) {
    this->real += c.real;
    this->imaginaria += c.imaginaria;
    return *this;
}

const Complex &Complex::operator-=(const Complex &c) {
    this->real -= c.real;
    this->imaginaria -= c.imaginaria;
    return *this;
}

Complex &Complex::operator++() {
    real++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    real++;
    return temp;
}

Complex &Complex::operator--() {
    real--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    real--;
    return temp;
}