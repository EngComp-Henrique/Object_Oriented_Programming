//
// Created by luis on 25/08/2021.
//

#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
using std::string;


class Imovel {
private:
    string address;
    int price;
public:
    Imovel(string = "No Address", int = 0);
    Imovel& setPrice(int);
    Imovel& setAddress(string);
    string getAddress() const {return address;}
    int getPrice() const;
};


#endif
