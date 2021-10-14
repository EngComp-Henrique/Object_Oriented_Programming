#ifndef INVALID_OPERATION_ERROR
#define INVALID_OPERATION_ERROR

#include <stdexcept>
using std::out_of_range;

class InvalidOperation : public out_of_range
{
    public:
        InvalidOperation(const char* e = "ERROR! Essa operação não é válida.") : out_of_range(e) {}
};

#endif