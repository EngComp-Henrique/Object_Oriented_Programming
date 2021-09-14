#include <iostream>
#include <string>

using namespace std;

bool temMaiuscula(string s)
{
    for(auto a: s){
        if(a < 97){
            return true;
        }
    }
    return false;
}

int main()
{
    string palavra;
    cout << "Digite uma palavra: ";
    cin >> palavra;
    if(temMaiuscula(palavra)){
        cout << palavra << " contém letra maiúscula" << endl;
    } else {
        cout << palavra << " não contém letra maiúscula" << endl;
    }
    return 0;
}