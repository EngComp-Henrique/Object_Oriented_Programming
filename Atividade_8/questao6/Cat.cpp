//
// Created by luis on 25/08/2021.
//

#include "Cat.h"

#include <string>
using std::string;

Cat::Cat(string catName): Animal(catName) {}

string Cat::meow() const {
    return "Meow, meow, meow...";
}

