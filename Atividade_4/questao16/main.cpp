//
// Created by luis on 28/07/2021.
//

#include "Carro.h"

int main() {
    Carro logan("Renault", 2018);
    Carro gol("Volkswagen", -1200);
    Carro camaro("Chevrolet");
    Carro palio("Fiat", 2023);
    Carro semNome("", 2020);

    logan.displayMessage();
    gol.displayMessage();
    camaro.displayMessage();
    palio.displayMessage();
    semNome.displayMessage();
    return 0;
}