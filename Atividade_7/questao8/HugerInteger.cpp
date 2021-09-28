//
// Created by luis on 04/08/2021.
//

#include "HugerInteger.h"
#include <bits/stdc++.h>

using std::cout, std::endl, std::string, std::ostream;

HugerInteger::HugerInteger() {

}

HugerInteger &HugerInteger::operator=(string number) {
    for (int i = 0; i < number.length(); i++){
        if (number[i] >= 48 && number[i] <= 57) {
            this->bigInt[i] = number[i];
            this->number_lengt++;
        } else {
            this->bigInt[0] = '0';
            this->number_lengt = 1;
            break;
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, const HugerInteger& number){
    for (int i = 0; i < number.number_lengt; i++){
        cout << number.bigInt[i];
    }
    cout << endl;
    return out;
}

bool HugerInteger::operator==(const HugerInteger &number) const {
    if (this->number_lengt < number.number_lengt || this->number_lengt > number.number_lengt)
        return false;
    int shorterNumber = this->number_lengt;
    if (number.number_lengt < shorterNumber)
        shorterNumber = number.number_lengt;
    for (int i = shorterNumber - 1; i >= 0; i--) {
        if (this->bigInt[i] != number.bigInt[i]) {
            return false;
        }
    }
    return true;
}

bool HugerInteger::operator!=(const HugerInteger &number) const {
    if(*this == number)
        return false;
    return true;
}

bool HugerInteger::operator>(const HugerInteger &number) const {
    if (this->number_lengt < number.number_lengt)
        return false;
    if (this->number_lengt > number.number_lengt)
        return true;
    for (int i = 0; i < this->number_lengt; i++) {
        if (this->bigInt[i] > number.bigInt[i]) {
            return true;
        }
    }
    return false;
}

bool HugerInteger::operator<(const HugerInteger &number) const {
    if (*this > number)
        return false;
    return true;
}

bool HugerInteger::operator>=(const HugerInteger &number) const {
    if (*this > number || *this == number)
        return true;
    return false;
}

bool HugerInteger::operator<=(const HugerInteger &number) const {
    if (*this < number || *this == number)
        return true;
    return false;
}

HugerInteger HugerInteger::operator+(const HugerInteger &number) const {
    string str_n1 = "", str_n2 ="";
    HugerInteger newInteger;

    for (int i = 0; i < this->number_lengt; i++) {
        str_n1 += this->bigInt[i];
    }

    for (int i = 0; i < number.number_lengt; i++) {
        str_n2 += number.bigInt[i];
    }

    if (str_n1.length() > str_n2.length())
        swap(str_n1, str_n2);

    string str_sum = "";
    int n1 = str_n1.length(), n2 = str_n2.length();

    reverse(str_n1.begin(), str_n1.end());
    reverse(str_n2.begin(), str_n2.end());

    int carry = 0;

    for (int i = 0; i < n1; i++) {
        int sum = ((str_n1[i] - '0') + (str_n2[i] - '0') + carry);
        str_sum.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++) {
        int sum = ((str_n2[i] - '0') + carry);
        str_sum.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str_sum.push_back(carry + '0');
    reverse(str_sum.begin(), str_sum.end());

    newInteger = str_sum;
    return newInteger;
}

const HugerInteger &HugerInteger::operator+=(const HugerInteger &number) {
    HugerInteger temp = *this + number;
    *this = temp;
    return *this;
}
