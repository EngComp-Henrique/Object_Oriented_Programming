//
// Created by luis on 04/08/2021.
//

#ifndef HUGERINTEGER_H
#define HUGERINTEGER_H
#include <string>
using std::string;

class HugerInteger {
private:
    char bigInt[40];
    int number_lengt = 0;
public:
    HugerInteger(string number);
    void input(string number);
    void output();
    void add(const HugerInteger &);
    bool isEqual(const HugerInteger &);
    bool isNotEqual(const HugerInteger &);
    bool isGreaterThan(const HugerInteger &);
    bool isLessThan(const HugerInteger &);
    bool isGreaterThanOrEqual(const HugerInteger &);
    bool isLessThanOrEqual(const HugerInteger &);
};


#endif
