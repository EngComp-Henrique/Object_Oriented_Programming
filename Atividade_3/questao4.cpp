#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int *aux = a;
    a = b;
    b = aux;
}

int main()
{
    int x, y, *ptr_x, *ptr_y;
    cout << "Digite dois valores separados por espaço: ";
    cin >> x >> y;
    ptr_x = &x;
    ptr_y = &y;
    cout << "Antes da função swap() -> x = " << x << " y = " << y << endl;
    swap(*ptr_x, *ptr_y);
    cout << "Depois da função swap() -> x = " << x << " y = " << y << endl;
    return 0;
}