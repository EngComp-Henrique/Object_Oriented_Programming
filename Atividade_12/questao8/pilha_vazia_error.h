#ifndef PILHA_VAZIA_ERROR
#define PILHA_VAZIA_ERROR

#include <stdexcept>
using std::out_of_range;

class PilhaVazia : public out_of_range
{
    public:
        PilhaVazia(const char* e = "Pilha está vazia!") : out_of_range(e) {}
};

#endif