#include <iostream>

std::string READ(const std::string& msg);
std::string EVAL(const std::string& evl);
std::string PRINT(const std::string& msg);
std::string rep(const std::string& input);

int main(int arg1, std::string arg2)
{
    std::string userMessage = "user> ";
    std::cout << rep(userMessage) << std::endl;

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