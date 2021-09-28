//
// Created by luis on 29/07/2021.
//

#include "Cupom.h"
#include <iostream>
using std::string;

Cupom::Cupom(string identificador, string desc, int quant, double preco) {
    setId(identificador);
    setDesc(desc);
    setQuantidade(quant);
    setPreco(preco);
}

void Cupom::setId(string novoId) {
    if (novoId == "")
        id = "Sem Id";
    else
        id = novoId;
}

void Cupom::setDesc(string novaDesc) {
    if (novaDesc == "")
        descricao = "Sem descrição";
    else
        descricao = novaDesc;
}

void Cupom::setQuantidade(int novaQuantidade) {
    if (novaQuantidade <= 0)
        quantidadeItem = 0;
    else
        quantidadeItem = novaQuantidade;
}

void Cupom::setPreco(double preco) {
    if (preco <= 0)
        precoItem = 0.00;
    else
        precoItem = preco;
}

string Cupom::getId() {
    return id;
}

string Cupom::getDesc() {
    return descricao;
}

int Cupom::getQuantidade() {
    return quantidadeItem;
}

double Cupom::getPreco() {
    return precoItem;
}

double Cupom::calculaCupom() {
    return getPreco() * getQuantidade();
}

void Cupom::displayInfo() {
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Descrição: " << getDesc() << std::endl;
    std::cout << "Quantidade disponível: " << getQuantidade() << std::endl;
    std::cout << "Preço (R$): " << getPreco() << std::endl;
    std::cout << "Cupom (R$): " << calculaCupom() << std::endl;
}
