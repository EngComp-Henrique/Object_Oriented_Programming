#include <iostream>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string palavra;
    cout << "Insira uma string: ";
    cin >> palavra;
    int n = palavra.size() * 2;
    cout.width(n);
    cout << palavra << endl;
    return 0;
}
