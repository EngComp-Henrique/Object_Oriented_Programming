//
// Created by luis on 11/08/2021.
//

#include "Pessoa.h"
#include <iostream>
using std::string, std::cout, std::endl;

Pessoa::Pessoa(string name, int age, float height) {
    setName(name);
    setAge(age);
    setHeight(height);
}

Pessoa::Pessoa() {

}

Pessoa& Pessoa::setName(string name) {
    if (name != "")
        this->name = name;
    else
        this->name = "'Sem nome'";
    return *this;
}

Pessoa& Pessoa::setAge(int age) {
    if (age <=0)
        this->age = 0;
    else
        this->age = age;
    return *this;
}

Pessoa&Pessoa::setHeight(float height) {
    if (height <= 0)
        this->height = 1.60;
    else
        this->height = height;
    return *this;
}

void Pessoa::getInfo() const {
    cout << "Nome: " << getName() << endl;
    cout << "Idade (em anos): " << getAge() << endl;
    cout << "Altura (em metros): " << getHeight() << endl;
}
