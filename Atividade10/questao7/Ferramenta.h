//
// Created by luis on 09/09/2021.
//

#ifndef FERRAMENTA_H
#define FERRAMENTA_H

class Ferramenta {
private:
    int numRegistro;
    char nomeFerramenta[40];
    int quantidade;
    float preco;
    bool presente;
public:
    Ferramenta(int = 0, const char[] = (const char*) "", int = 0, float = 0.0);
    int getNumRegistro() const {return numRegistro;}
    const char* getNomeFerramenta() {return nomeFerramenta;}
    int getQuantidade() const {return quantidade;}
    float getPreco() const {return preco;}
    Ferramenta& setNumRegistro(int);
    Ferramenta& setNomeFerramenta(const char*);
    Ferramenta& setQuantidade(int);
    Ferramenta& setPreco(float);
};


#endif
