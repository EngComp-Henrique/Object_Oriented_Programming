#include <iostream>

using namespace std;

int sequencia()
{
    static int v = 0;
    return v++;
}

int main() 
{
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;

    return 0;
}