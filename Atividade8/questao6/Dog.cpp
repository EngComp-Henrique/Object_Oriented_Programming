//
// Created by luis on 25/08/2021.
//

#include "Dog.h"

#include <string>
using std::string;

Dog::Dog(string dogName): Animal(dogName) {}

string Dog::bark() const{
    return "Au, au, au...";
}


