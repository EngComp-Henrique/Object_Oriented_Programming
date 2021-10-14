#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using std::cout;
using std::endl;

#include <string.h>
#include <ctype.h>

#include <ctime>

#include <string>
using std::string;

#include "WrongDataError.h"

class Pessoa
{
private:
    string name;
    string address;
    string phoneNumber;
    string email;
    bool phoneValidation(string phone)
    {
        int count_digits = 0, count_dash = 0;
        for (auto i: phone) {
            if (isdigit(i))
                count_digits++;
            else if (i == '-')
                count_dash++;
        }
        if (count_dash == 1 && count_digits == 8)
            return true;
        return false; // Lançar um erro
    }

public:
    Pessoa(string newName = "", string newAdd = "", string newPhone = "", string newEmail = "") {
        setName(newName);
        setAdd(newAdd);
        setPhone(newPhone);
        setEmail(newEmail);
    };

    virtual ~Pessoa() {};
    Pessoa& setAdd(string add)
    {
        if (add != "") {
            this->address = add;
            return *this;
        } else {
            throw WrongDataError();
        }
    }

    Pessoa& setPhone(string phone)
    {
        if (phoneValidation(phone)) {
            this->phoneNumber = phone;
            return *this;
        }
        else {
            throw WrongDataError();
        }
    }

    Pessoa& setEmail(string em)
    {
        if (em != "") {
            this->email = em;
            return *this;
        } else {
            throw WrongDataError();
        }
    }
    Pessoa& setName(string newName)
    {
        if (newName != "") {
            this->name = newName;
            return *this;
        } else {
            throw WrongDataError();
        }
    }
    string getAddress() const {return address;}
    string getPhone() const {return phoneNumber;}
    string getEmail() const {return email;}
    string getName() const {return name;}
    virtual void getInfoAccount() const = 0;
};

#endif