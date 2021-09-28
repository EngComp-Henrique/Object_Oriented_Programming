//
// Created by luis on 25/08/2021.
//

#include "Animal.h"
#include <string>
using std::string;

Animal::Animal(string nameRegistered): name(nameRegistered){

}

Animal::Animal() {

}

string Animal::walk() const {
    return name + " is Walking...";
}
