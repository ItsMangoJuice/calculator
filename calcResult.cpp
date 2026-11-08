#include "Headers/calcResult.h"
#include <string>
#include <vector>
#include <utility>
#include "Headers/exceptions.h"
#include <cmath>
#include <string_view>
#include <cstddef>

enum class Operations
{
    Addition,
    Subtraction,
    Multiplication,
    Division,
    Power,
    Modulo
};

std::pair<std::size_t, Operations> findOperation(const std::vector<std::string>& arguments)
{
    for (std::size_t i = arguments.size() - 2; i >= 1; i -= 2)
    {
        std::string_view op{arguments.at(i)};
        if (op == "^")
            return std::pair<std::size_t, Operations>{i, Operations::Power};
        if (i == 1) break;
    }
    for (std::size_t i = 1; i < arguments.size(); i += 2)
    {
        std::string_view op{arguments.at(i)};
        if (op == "*" || op == "/" || op == "%")
        {
            if (op == "*")
                return std::pair<std::size_t, Operations>{i, Operations::Multiplication};
            else if (op == "%")
                return std::pair<std::size_t, Operations>{i, Operations::Modulo};
            else
                return std::pair<std::size_t, Operations>{i, Operations::Division};
        }
    }
    for (std::size_t i = 1; i < arguments.size(); i += 2)
    {
        std::string_view op{arguments.at(i)};
        if (op == "+" || op == "-")
        {
            if (op == "+")
                return std::pair<std::size_t, Operations>{i, Operations::Addition};
            else
                return std::pair<std::size_t, Operations>{i, Operations::Subtraction};
        }
    }
    throw Exceptions::OperatorNotFound();
}

double doOperation(double operand1, double operand2, Operations op)
{
    double result{};
    switch (op)
    {
    case Operations::Multiplication:
        result = operand1 * operand2;
        break;
    case Operations::Division:
        if (operand2 == 0) throw Exceptions::DivisionByZero();
        result = operand1 / operand2;
        break;
    case Operations::Addition:
        result = operand1 + operand2;
        break;
    case Operations::Subtraction:
        result = operand1 - operand2;
        break;
    case Operations::Power:
        if (operand1 < 0 && operand2 != std::trunc(operand2))
            throw Exceptions::BadInput("A negative base cannot have a non-integer exponent in real arithmetic!");
        if (operand1 == 0 && operand2 < 0)
            throw Exceptions::BadInput("Base of power can't be zero while exponent is a negative number!");
        result = std::pow(operand1, operand2);
        break;
    case Operations::Modulo:
        if (operand2 == 0) throw Exceptions::DivisionByZero();
        result = std::fmod(operand1, operand2);
        break;
    default:
        throw Exceptions::OperatorNotSupported();
    }
    if (!std::isfinite(result)) throw Exceptions::BadInput("The operation resulted in a non-finite value!");
    return result;
}

std::vector<std::string> rearrange(std::string result, std::size_t index, const std::vector<std::string>& arguments)
{
    std::vector<std::string> temp;
    temp.reserve(arguments.size() - 2);
    temp.insert(temp.end(), arguments.begin(), arguments.begin() + static_cast<std::ptrdiff_t>(index));
    temp.push_back(result);
    temp.insert(temp.end(), arguments.begin() + static_cast<std::ptrdiff_t>(index) + 3, arguments.end());
    return temp;
}

double calcResult(std::vector<std::string>& arguments)
{
    while (arguments.size() > 1)
    {
        auto operation{findOperation(arguments)};

        auto index{operation.first};
        Operations op{operation.second};
        auto operand1{std::stod(arguments.at(index - 1))};
        auto operand2{std::stod(arguments.at(index + 1))};

        auto result{doOperation(operand1, operand2, op)};

        arguments = rearrange(std::to_string(result), index - 1, arguments);
    }
    return std::stod(arguments.at(0));
}
