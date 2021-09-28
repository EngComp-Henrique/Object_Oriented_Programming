#include <iostream>
#include <string>

using namespace std;

void converteParaMinusculas(string &s)
{
    for(auto &c: s){
        c = tolower(c);
    }
}

int main()
{
    string palavra;
    cout << "Digite uma palavra: ";
    cin >> palavra;
    string &palavraMaiuscula = palavra; 
    cout << "Palavra original: " << palavra << endl;
    converteParaMinusculas(palavraMaiuscula);
    cout << "Palavra após conversão de letra para maiúscula: " << palavra << endl;
    return 0;
}