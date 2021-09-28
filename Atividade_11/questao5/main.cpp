#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

template<typename T1, typename T2>
bool compara(const T1& obj1, const T2& obj2) {
    return obj1 == obj2;
}

int main() {
    cout << "Comparação de string" << endl;
    cout << "Luis é igual a Luis? " << (compara<string>("Luis", "luis") ? "Sim" : "Não") << endl;
    cout << "Henrique é igual a Henrique? " << (compara<string>("Henrique", "Henrique") ? "Sim" : "Não") << endl << endl;

    cout << "Comparando números inteiros" << endl;
    cout << "2 == 3? " << (compara<int>(2, 3) ? "Sim" : "Não") << endl;
    cout << "2 == 2? " << (compara<int>(2, 2) ? "Sim" : "Não") << endl << endl;

    cout << "Comparando números de ponto fluante" << endl;
    cout << "2.5 == 3.1? " << (compara<float>(2.5, 3.1) ? "Sim" : "Não") << endl;
    cout << "2.45 == 2.45? " << (compara<float>(2.45f, 2.45f) ? "Sim" : "Não") << endl;
    return 0;
}
