#include <iostream>
using std::cout, std::endl, std::right, std::left;

#include <iomanip>
using std::setw;

int main() {
    cout << "Tabela ASCII" << endl;
    cout << "N°  | Valor" << endl;
    cout.fill(' ');
    for (int i = 33; i < 127; i++) {
        cout << setw(3) << left << i << " " << "|" << " " << right << setw(4);
        cout.put(i);
        cout << endl;
    }
    return 0;
}
