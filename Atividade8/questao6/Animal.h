//
// Created by luis on 25/08/2021.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using std::string;

class Animal {
protected:
    string name;
    string race;

public:
    Animal(string = "No named");
    Animal();
    string walk() const;
};


#endif
