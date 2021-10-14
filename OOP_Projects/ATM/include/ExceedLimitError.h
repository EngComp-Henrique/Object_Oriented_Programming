#ifndef EXCEED_LIMIT_ERROR
#define EXCEED_LIMIT_ERROR

#include <stdexcept>
using std::underflow_error;

class ExceedLimit : public underflow_error
{
public:
    ExceedLimit(const char* e = "ERROR! Valor sacado/transferido é maior que o permitido") : underflow_error(e) {}
};

#endif