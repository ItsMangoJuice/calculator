#include "Headers/parseInput.h"
#include "Headers/exceptions.h"

std::vector<std::string> parseInput(const int argc, const char* const argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (size_t i = 0; i < arguments.size(); i = i + 2)
    {
        try
        {
            std::stod(arguments.at(i));
        }
        catch (const std::exception& e)
        {
            throw Exceptions::BadInput();
        }
    }
    for (size_t i = 1; i < arguments.size(); i = i + 2)
    {
        std::string_view op{arguments.at(i)};
        if (op == "+" || op == "-" || op == "*" || op == "/")
            continue;
        throw Exceptions::BadInput();
    }
    return arguments;
}
