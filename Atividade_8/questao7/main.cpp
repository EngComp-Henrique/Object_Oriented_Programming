#include <iostream>
using std::cout, std::endl;

#include "Imovel.h"
#include "ImovelNovo.h"
#include "ImovelVelho.h"



int main() {
    char line[] = "--------------------------\n";
    Imovel p1("Ipanema", 50000);
    ImovelNovo p2("SoHo", 33000, 1500);
    ImovelVelho p3("Harlem", 15000, 5000);

    cout << "Property 1:" << endl;
    cout << "Address: " << p1.getAddress() << endl;
    cout << "Price (US$): " << p1.getPrice() << endl;
    cout << line;

    cout << "Property 2:" << endl;
    cout << "Address: " << p2.getAddress() << endl;
    cout << "Price (US$): " << p2.getPrice() << endl;
    cout << "Increase (US$): " << p2.getSurcharge() << endl;
    cout << line;

    cout << "Property 3:" << endl;
    cout << "Address: " << p3.getAddress() << endl;
    cout << "Price (US$): " << p3.getPrice() << endl;
    cout << "Discount (US$): " << p3.getReduction() << endl;
    cout << line;

    p2.setSurcharge(1000);
    p3.setReduction(6000);
    p1.setPrice(55000);
    p1.setAddress("Queens");

    cout << "Property 1:" << endl;
    cout << "Address: " << p1.getAddress() << endl;
    cout << "Price (US$): " << p1.getPrice() << endl;
    cout << line;

    cout << "Property 2:" << endl;
    cout << "Address: " << p2.getAddress() << endl;
    cout << "Price (US$): " << p2.getPrice() << endl;
    cout << "Increase (US$): " << p2.getSurcharge() << endl;
    cout << line;

    cout << "Property 3:" << endl;
    cout << "Address: " << p3.getAddress() << endl;
    cout << "Price (US$): " << p3.getPrice() << endl;
    cout << "Discount (US$): " << p3.getReduction() << endl;
    cout << line;
    return 0;
}
