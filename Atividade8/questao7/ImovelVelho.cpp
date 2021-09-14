//
// Created by luis on 25/08/2021.
//

#include "ImovelVelho.h"

ImovelVelho::ImovelVelho(string add, int price, int discount) : Imovel(add, price) {
    setReduction(discount);
}

ImovelVelho &ImovelVelho::setReduction(int reduction) {
    this->reduction = (reduction > 0) ? reduction : 0;
    return *this;
}

int ImovelVelho::getPrice() const {
    return Imovel::getPrice() - getReduction();
}
