#include <iostream>
#include <vector>
#include <string>
#include "Headers/parseInput.h"
#include "Headers/exceptions.h"
#include "Headers/calcResult.h"

int reportUsage()
{
    std::cout << "Usage: number operation number operation number ...\n";
    std::cout << "Supported operations: addition(+), subtraction(-), multiplication(*), division(/)\n";
    std::cout << "Example: 1 + 5 * 6";
    return 1;
}

int main(int argc, char* argv[])
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

    std::cout << calcResult(arguments);

    return 0;
}
