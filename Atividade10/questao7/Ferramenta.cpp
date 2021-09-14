//
// Created by luis on 09/09/2021.
//

#include "Ferramenta.h"

#include <cstring>
using std::strcpy;

Ferramenta::Ferramenta(int num, const char nome[], int qt, float pr){
    setNumRegistro(num);
    setNomeFerramenta(nome);
    setQuantidade(qt);
    setPreco(pr);
    this->presente = true;
}

Ferramenta &Ferramenta::setNumRegistro(int novoNum) {
    if (novoNum < 0)
        novoNum = 0;
    else if (novoNum > 99)
        novoNum = 99;
    this->numRegistro = novoNum;
    return *this;
}

Ferramenta &Ferramenta::setNomeFerramenta(const char novoNome[]) {
    strcpy(this->nomeFerramenta, novoNome);
    return *this;
}

Ferramenta &Ferramenta::setQuantidade(int novaQuant) {
    if (novaQuant >= 0)
        this->quantidade = novaQuant;
    else
        this->quantidade = 0;
    return *this;
}

Ferramenta &Ferramenta::setPreco(float novoPreco) {
    if(novoPreco >= 0.0)
        this->preco = novoPreco;
    else
        this->preco = 0.0;
    return *this;
}



