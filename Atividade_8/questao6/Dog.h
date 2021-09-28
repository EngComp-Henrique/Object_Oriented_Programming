//
// Created by luis on 25/08/2021.
//

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

#include <string>
using std::string;

class Dog: public Animal{
public:
    Dog(string);
    string bark() const;

};


#endif
