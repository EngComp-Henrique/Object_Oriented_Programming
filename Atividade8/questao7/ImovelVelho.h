//
// Created by luis on 25/08/2021.
//

#ifndef IMOVELVELHO_H
#define IMOVELVELHO_H

#include <string>
using std::string;

#include "Imovel.h"

class ImovelVelho: public Imovel{
private:
    int reduction;
public:
    ImovelVelho(string, int , int );
    int getReduction() const {return reduction;}
    ImovelVelho& setReduction(int);
    int getPrice() const;
};


#endif
