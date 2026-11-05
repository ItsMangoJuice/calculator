#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

namespace Exceptions
{
    class BadInput : public std::runtime_error
    {
    public:
        BadInput() : std::runtime_error("Bad Input!") {}
    };

    class OperatorNotFound : public std::runtime_error
    {
    public:
        OperatorNotFound() : std::runtime_error("No Operator Found!") {}
    };

    class OperatorNotSupported : public std::runtime_error
    {
    public:
        OperatorNotSupported() : std::runtime_error("Operator Is Not Supported!") {}
    };
}

#endif
