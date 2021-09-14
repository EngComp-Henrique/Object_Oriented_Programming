//
// Created by luis on 29/07/2021.
//

#ifndef DATA_H
#define DATA_H

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano);
    void setDia(int novoDia);
    void setMes(int novoMes);
    void setAno(int novoAno);
    int getDia();
    int getMes();
    int getAno();
    void mostrarData();
};


#endif
