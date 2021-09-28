//
// Created by luis on 25/08/2021.
//

#ifndef CAT_H
#define CAT_H

#include <string>
using std::string;

#include "Animal.h"

class Cat: public Animal{
public:
    Cat(string);
    string meow() const;
};


#endif
