#include <iostream>
using std::cout, std::endl;

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main() {
    Cat cat("Fujão");
    Dog dog("Rex");
    cout << dog.bark() << endl;
    cout << cat.meow() << endl;
    cout << dog.walk() << endl;
    cout << cat.walk() << endl;

    return 0;
}
