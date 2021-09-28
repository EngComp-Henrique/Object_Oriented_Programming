//
// Created by luis on 04/08/2021.
//

#include "retangulo.h"
#include <iostream>
using std::cout, std::endl;

retangulo::retangulo(double height, double width) {
    setHeight(height);
    setWidth(width);
}

void retangulo::setHeight(double new_height) {
    height = (new_height >= 0.0 && new_height <= 20.0) ? new_height:1;
}

void retangulo::setWidth(double new_width) {
    width = (new_width >= 0.0 && new_width <= 20.0) ? new_width:1;
}

double retangulo::perimeter() {
    return 2 * getWidth() + 2 * getHeight();
}

double retangulo::area() {
    return getHeight() * getWidth();
}

void retangulo::displayArea() {
    cout << "Área do retângulo (m^2): " << area() << endl;
}

void retangulo::displayPerimeter() {
    cout << "Perímetro do retângulo (m^2): " << perimeter() << endl;
}