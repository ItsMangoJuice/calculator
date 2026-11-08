#include "Headers/parseInput.h"
#include "Headers/exceptions.h"
#include <cstddef>

std::vector<std::string> parseInput(int argc, const char* const argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    if (arguments.empty() || arguments.size() % 2 == 0 || arguments.size() < 3)
        throw Exceptions::BadInput("The number of arguments must be odd and at least 3");

    for (std::size_t i = 0; i < arguments.size(); i += 2)
    {
        std::size_t pos{};
        std::stod(arguments.at(i), &pos);
        if (pos != arguments.at(i).size()) throw Exceptions::BadInput("Numbers contain invalid characters!");
    }
    for (std::size_t i = 1; i < arguments.size(); i += 2)
    {
        std::string_view op{arguments.at(i)};
        if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^")
            continue;
        throw Exceptions::BadInput("Invalid characters passed in as operator!");
    }
    return arguments;
}
