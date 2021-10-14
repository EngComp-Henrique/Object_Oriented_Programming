#ifndef INSUFFICIENT_FUNDS_ERROR
#define INSUFFICIENT_FUNDS_ERROR

#include <stdexcept>
using std::underflow_error;

class InsufficientFund : public underflow_error
{
    public:
        InsufficientFund(const char* e = "ERROR! Você não possui saldo suficiente.") : underflow_error(e) {}
};

#endif