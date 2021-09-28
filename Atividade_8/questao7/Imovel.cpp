//
// Created by luis on 25/08/2021.
//

#include "Imovel.h"

using std::string;

Imovel::Imovel(string add, int price) {
    setAddress(add);
    setPrice(price);
}

Imovel &Imovel::setPrice(int price) {
    this->price = (price >= 0) ? price:0; return *this;
}

Imovel &Imovel::setAddress(string addr) {
    this->address = addr;
    return *this;
}

int Imovel::getPrice() const {
    return price;
}
