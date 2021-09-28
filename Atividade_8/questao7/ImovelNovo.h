//
// Created by luis on 25/08/2021.
//

#ifndef IMOVELNOVO_H
#define IMOVELNOVO_H

#include <string>
using std::string;

#include "Imovel.h"

class ImovelNovo: public Imovel{
private:
    int surcharge;
public:
    ImovelNovo(string, int, int);
    int getSurcharge() const {return surcharge;}
    ImovelNovo& setSurcharge(int newSurcharge);
    int getPrice() const;
};


#endif
