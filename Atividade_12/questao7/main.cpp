#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <stdexcept>
using std::runtime_error;
using std::overflow_error;
using std::underflow_error;
using std::range_error;


void run_error() {
    throw runtime_error("Erro de run time");
}

void over_error() {
    throw overflow_error("Erro de over flow");
}

void under_error() {
    throw underflow_error("Erro de under flow");
}

int main() {

    try
    {
        run_error();
    }
    catch(runtime_error & e)
    {
        cerr << "Erro 1 capturador" << endl;
        cerr << e.what() << endl;
    }
    cout << endl;

    try
    {
        over_error();
    }
    catch(overflow_error & e)
    {
        cerr << "Erro 2 capturador" << endl;
        cerr << e.what() << endl;
    }
    cout << endl;

    try
    {
        under_error();
    }
    catch(underflow_error & e)
    {
        cerr << "Erro 3 capturador" << endl;
        cerr << e.what() << endl;
    }
    cout << endl << "Fluxo segue..." << endl;
    
    return 0;
}