#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

int main()
{
    int x, y;
    cout << "Digite dois valores separados por espaço: ";
    cin >> x >> y;
    int &ptr_x = x;
    int &ptr_y = y;
    cout << "Antes da função swap() -> x = " << x << " y = " << y << endl;
    swap(ptr_x, ptr_y);
    cout << "Depois da função swap() -> x = " << x << " y = " << y << endl;
    return 0;
}