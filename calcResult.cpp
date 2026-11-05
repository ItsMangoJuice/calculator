#include "Headers/calcResult.h"
#include <string>
#include <vector>
#include <utility>
#include "Headers/exceptions.h"

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

std::pair<std::size_t, Operations> findOperation(const std::vector<std::string>& arguments)
{
    for (size_t i = 1; i < arguments.size(); i = i + 2)
    {
        std::string op{arguments.at(i)};
        if (op == "*" || op == "/")
        {
            if (op == "*")
                return std::pair<std::size_t, Operations>{i, Operations::Multiplication};
            else
                return std::pair<std::size_t, Operations>{i, Operations::Division};
        }
    }
    for (size_t i = 1; i < arguments.size(); i = i + 2)
    {
        std::string op{arguments.at(i)};
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
    switch (op)
    {
    case Operations::Multiplication:
        return operand1 * operand2;
    case Operations::Division:
        return operand1 / operand2;
    case Operations::Addition:
        return operand1 + operand2;
    case Operations::Subtraction:
        return operand1 - operand2;
    default:
        throw Exceptions::OperatorNotSupported();
    }
}

std::vector<std::string> rearrange(std::string result, std::size_t index, std::vector<std::string>& arguments)
{
    std::vector<std::string> temp;
    temp.reserve(arguments.size() - 2);
    for (size_t i = 0; i < index; i++)
    {
        temp.push_back(arguments.at(i));
    }
    temp.push_back(result);
    for (size_t i = index + 3; i < arguments.size(); i++)
    {
        temp.push_back(arguments.at(i));
    }
    return temp;
}
