#ifndef INEXISTENT_ACCOUNT_ERROR
#define INEXISTENT_ACCOUNT_ERROR

#include <stdexcept>
using std::runtime_error;

class InexistentAccountError : public runtime_error
{
    public:
        InexistentAccountError(const char* e = "Error! Essa conta não existe.") : runtime_error(e) {}
};

#endif
