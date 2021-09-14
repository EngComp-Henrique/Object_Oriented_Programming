//
// Created by luis on 29/07/2021.
//

#ifndef CUPOM_H
#define CUPOM_H
#include <string>
using std::string;

class Cupom {
private:
    string id, descricao;
    int quantidadeItem;
    double precoItem;
public:
    Cupom(string identificador, string desc, int quant, double preco);
    void setId(string novoId);
    void setDesc(string novaDesc);
    void setQuantidade(int novaQuantidade);
    void setPreco(double preco);
    string getId();
    string getDesc();
    int getQuantidade();
    double getPreco();
    double calculaCupom();
    void displayInfo();
};


#endif
