#include <iostream>

std::string READ(const std::string& msg);
std::string EVAL(const std::string& evl);
std::string PRINT(const std::string& msg);
std::string rep(const std::string& input);
bool getUserPrompt(const std::string& prompt, std::string& input);

int main(int argc, char* argv[])
{
    std::string userMessage = "user> ";
    std::string input;

    while (getUserPrompt(userMessage, input))
    {
        std::cout << rep(input) << std::endl;
    }

    return 0;
}

bool getUserPrompt(const std::string& prompt, std::string& input)
{
    std::cout << prompt;
    std::getline(std::cin, input);

    if (std::cin.eof())
    {
        std::cout << std::endl;
        return false;
    }

    return true;
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