#include <iostream>
using std::cout, std::cin, std::endl, std::fixed, std::right;

#include <iomanip>
using std::setw;

int main() {
    double temp_grau;
    int temp_fahr;

    cout << "Digite um valor para uma temperatura (°F): ";
    cin >> temp_fahr;

    temp_grau = 5.0 / 9.0 * (temp_fahr - 32);

    cout << fixed;
    cout.precision(3);
    cout << "Temperatura em graus celsius:" << setw(3) << " " << right << temp_grau << endl;
    cout.precision(0);
    cout << "Temperatura em graus fahrenheit:" << setw(3) << " " << right << temp_fahr << endl;
    return 0;
}
