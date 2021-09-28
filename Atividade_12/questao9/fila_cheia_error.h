#ifndef FILA_CHEIA_ERROR
#define FILA_CHEIA_ERROR

#include <stdexcept>
using std::out_of_range;

class FilaCheia : public out_of_range
{
    public:
        FilaCheia(const char* e = "Fila está cheia!") : out_of_range(e) {}
};
#endif