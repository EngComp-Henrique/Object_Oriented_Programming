//
// Created by luis on 04/08/2021.
//

#ifndef HUGERINTEGER_H
#define HUGERINTEGER_H
#include <string>
#include <iostream>

using std::string, std::ostream;

class HugerInteger {
    friend ostream &operator<<(ostream &, const HugerInteger &);
private:
    char bigInt[40];
    int number_lengt = 0;
public:
    HugerInteger();
    HugerInteger &operator=(string);
    HugerInteger operator+(const HugerInteger &) const;
    const HugerInteger &operator+=(const HugerInteger &);
    bool operator==(const HugerInteger &) const;
    bool operator!=(const HugerInteger &) const;
    bool operator>(const HugerInteger &) const;
    bool operator<(const HugerInteger &) const;
    bool operator>=(const HugerInteger &) const;
    bool operator<=(const HugerInteger &) const;
};


#endif