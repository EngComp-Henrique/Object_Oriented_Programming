#ifndef FILA_VAZIA_ERROR
#define FILA_VAZIA_ERROR

#include <stdexcept>
using std::out_of_range;

class FilaVazia : public out_of_range
{
    public:
        FilaVazia(const char* e = "Fila está vazia!") : out_of_range(e) {}
};
#endif