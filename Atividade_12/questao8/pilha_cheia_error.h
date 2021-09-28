#ifndef PILHA_CHEIA_ERROR
#define PILHA_CHEIA_ERROR

#include <stdexcept>
using std::out_of_range;

class PilhaCheia : public out_of_range 
{
    public:
        PilhaCheia(const char* e = "Pilha está cheia!") : out_of_range(e) {} 
};

#endif