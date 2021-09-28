//
// Created by luis on 04/08/2021.
//

#ifndef RETANGULO_H
#define RETANGULO_H


class retangulo {
private:
    double height, width;
    double area();
    double perimeter();

public:
    retangulo(double = 1.0, double = 1.0);
    void setHeight(double);
    void setWidth(double);
    inline double getHeight() {return height;}
    inline double getWidth() {return width;}
    void displayArea();
    void displayPerimeter();
};


#endif
