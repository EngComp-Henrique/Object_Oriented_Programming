#ifndef WRONG_DATA_ERROR
#define WRONG_DATA_ERROR

#include <stdexcept>
using std::invalid_argument;

class WrongDataError : public invalid_argument
{
    public:
        WrongDataError(const char* e = "ERROR! Entrada de dado é inválida") : invalid_argument(e) {}
};

#endif
