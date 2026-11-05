#ifndef CALCRESULT_H
#define CALCRESULT_H
#include <vector>
#include <string>
#include <utility>

enum class Operations
{
    Addition,
    Subtraction,
    Multiplication,
    Division
};

double calcResult(std::vector<std::string>& arguments);
std::pair<std::size_t, Operations> findOperation(std::vector<std::string>& arguments);
double doOperation(double operand1, double operand2, Operations op);
std::vector<std::string> rearrange(std::string result, std::size_t index, std::vector<std::string>& arguments);

#endif
