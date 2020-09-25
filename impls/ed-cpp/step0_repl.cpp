#include <iostream>

std::string READ(const std::string& msg);
std::string EVAL(const std::string& evl);
std::string PRINT(const std::string& msg);
std::string rep(const std::string& input);

int main(int argi, char* argc[])
{
    std::string userMessage = "user> ";
    std::string input;
    std::cout << userMessage << std::endl;

    while (std::getline(std::cin, input))
    {
        std::cout << userMessage << std::endl;
        std::cout << rep(input) << std::endl;
    }

    return 0;
}

std::string READ(const std::string& input)
{
    return input;
}

std::string EVAL(const std::string& input)
{
    return input;
}

std::string PRINT(const std::string& input)
{
    return input;
}

std::string rep(const std::string& input)
{
    return PRINT(EVAL(READ(input)));
}