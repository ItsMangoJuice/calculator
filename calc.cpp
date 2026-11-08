#include <iostream>
#include <vector>
#include <string>
#include "Headers/parseInput.h"
#include "Headers/exceptions.h"
#include "Headers/calcResult.h"

int reportUsage()
{
    std::cout << "Usage: number operation number operation number ...\n";
    std::cout << "Supported operations: addition(+), subtraction(-), multiplication(*), division(/), power(^), modulo(%)\n";
    std::cout << "Example: 1 + 5 * 6";
    return 1;
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc == 1) return reportUsage();

        std::vector<std::string> arguments;
        try
        {
            arguments = parseInput(argc, argv);
        }
        catch (const Exceptions::BadInput& e)
        {
            std::cerr << e.what() << '\n';
            return reportUsage();
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid characters passed in as number!";
            return 1;
        }

        try
        {
            std::cout << calcResult(arguments) << '\n';
        }
        catch (const Exceptions::DivisionByZero& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        catch (const Exceptions::BadInput& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

}
