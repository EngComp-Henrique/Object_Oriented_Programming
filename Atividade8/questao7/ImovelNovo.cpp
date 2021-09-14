//
// Created by luis on 25/08/2021.
//

#include "ImovelNovo.h"

ImovelNovo::ImovelNovo(string add, int price, int sur) : Imovel(add, price), surcharge(sur) {
}

ImovelNovo &ImovelNovo::setSurcharge(int newSurcharge) {
    this->surcharge = (newSurcharge > 0) ? newSurcharge : 0;
    return *this;
}

int ImovelNovo::getPrice() const {
    return Imovel::getPrice() + getSurcharge();
}
