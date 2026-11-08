#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>

namespace Exceptions
{
    class BadInput : public std::runtime_error
    {
    public:
        BadInput() : std::runtime_error("Bad input!") {}
        BadInput(std::string msg) : std::runtime_error(msg) {}
    };

    class OperatorNotFound : public std::runtime_error
    {
    public:
        OperatorNotFound() : std::runtime_error("No operator found!") {}
    };

    class OperatorNotSupported : public std::runtime_error
    {
    public:
        OperatorNotSupported() : std::runtime_error("Operator is not supported!") {}
    };

    class DivisionByZero : public std::runtime_error
    {
    public:
        DivisionByZero() : std::runtime_error("Division by zero is not allowed!") {}
    };
}

#endif
