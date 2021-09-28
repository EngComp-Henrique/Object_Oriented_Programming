//
// Created by luis on 04/08/2021.
//

#include "HugerInteger.h"
#include <bits/stdc++.h>

using std::cout, std::endl, std::string;

HugerInteger::HugerInteger(string number) {
    input(number);
}

void HugerInteger::input(string number) {
    number_lengt = 0;
    for (int i = 0; i < number.length(); i++){
        if (number[i] >= 48 && number[i] <= 57) {
            bigInt[i] = number[i];
            number_lengt++;
        } else {
            bigInt[0] = '0';
            number_lengt = 1;
            break;
        }
    }
}

void HugerInteger::output() {
    for (int i = 0; i < number_lengt; i++){
        cout << bigInt[i];
    }
    cout << endl;
}

bool HugerInteger::isEqual(const HugerInteger &number) {
    if (number_lengt < number.number_lengt || number_lengt > number.number_lengt)
        return false;
    int shorterNumber = number_lengt;
    if (number.number_lengt < shorterNumber)
        shorterNumber = number.number_lengt;
    for (int i = shorterNumber - 1; i >= 0; i--) {
        if (bigInt[i] != number.bigInt[i]) {
            return false;
        }
    }
    return true;
}

bool HugerInteger::isNotEqual(const HugerInteger &number) {
    if(isEqual(number))
        return false;
    return true;
}

bool HugerInteger::isGreaterThan(const HugerInteger &number) {
    if (number_lengt < number.number_lengt)
        return false;
    if (number_lengt > number.number_lengt)
        return true;
    for (int i = 0; i < number_lengt; i++) {
        if (bigInt[i] > number.bigInt[i]) {
            return true;
        }
    }
    return false;
}

bool HugerInteger::isLessThan(const HugerInteger &number) {
    if (isGreaterThan(number))
        return false;
    return true;
}

bool HugerInteger::isGreaterThanOrEqual(const HugerInteger &number) {
    if (isEqual(number) || isGreaterThan(number))
        return true;
    return false;
}

bool HugerInteger::isLessThanOrEqual(const HugerInteger &number) {
    if (isLessThan(number) || isEqual(number))
        return true;
    return false;
}

void HugerInteger::add(const HugerInteger &number) {
    string str_n1 = "", str_n2 ="";
    for (int i = 0; i < number_lengt; i++) {
        str_n1 += bigInt[i];
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
    input(str_sum);
}

