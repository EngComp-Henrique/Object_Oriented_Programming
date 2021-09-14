#include <iostream>
using std::cout, std::endl, std::cin;

using std::left, std::right;

using std::string;

using std::fixed;

#include <fstream>
using std::ofstream, std::ifstream;

#include <iomanip>
using std::setw, std::setfill;

typedef struct dados {
    string d_tipo;
    int bytes;
} TIPOS;

bool salvarDados(TIPOS t[], int n) {
    ofstream file;
    file.open("dados.dat", std::ios::out);

    if (!file)
        return false;

    for (int i = 0; i < n; i++) {
        file << left;
        file << t[i].d_tipo;
        file << right;
        file.fill(' ');
        int a = 17 - t[i].d_tipo.size();
        if (t[i].bytes <= 9)
            a++;
        file << setw(a) << " " << t[i].bytes << endl;
    }

    file.close();
    return true;
}

bool listarDados() {
    ifstream file;
    file.open("dados.dat", std::ios::in);

    if(!file)
        return false;

    TIPOS t;

    cout << fixed;
    cout <<  "Tipo de dado" << "  " << "Quantidade de bytes" << endl;
    if (file.is_open()) {
        string tp;
        while (getline(file, tp))
            cout << tp << endl;
        file.close();
    }
    return true;
}

TIPOS DADOS[9] {
    {"char", sizeof(char)},
    {"unsigned char", sizeof(unsigned char)},
    {"short int", sizeof(short int)},
    {"int", sizeof(int)},
    {"long", sizeof(long)},
    {"long long", sizeof(long long)},
    {"float", sizeof(float)},
    {"double", sizeof(long double)},
    {"long double", sizeof(long double)}
};

int main() {
    if (salvarDados(DADOS, 9)) cout << "Dados salvos com sucesso" << endl;
    else cout << "ERRO!" << endl;
    int op;
    cout << "Deseja ver os dados? ";
    cin >> op;
    switch (op) {
        case 0:
            listarDados();
            break;
        default:
            break;
    }
    return 0;
}
