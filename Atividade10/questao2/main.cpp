#include <iostream>
using std::cout, std::endl, std::fixed;

//#include <iomanip>
//using std::setprecision;

int main() {
    double n = 100.453627;
    cout << fixed;
    cout.precision(1);
    cout << "n com 1 casa decimal: " << n << endl;
    cout.precision(2);
    cout << "n com 2 casa decimal: " << n << endl;
    cout.precision(3);
    cout << "n com 3 casa decimal: " << n << endl;
    cout.precision(4);
    cout << "n com 4 casa decimal: " << n << endl;
    return 0;
}
