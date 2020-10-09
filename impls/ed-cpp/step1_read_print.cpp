#include <iostream>
#include "Reader.h"

String READ(const String& msg);
String EVAL(const String& evl);
String PRINT(const String& msg);
String rep(const String& input);
bool getUserPrompt(const String& prompt, String& input);

int main(int argc, char* argv[])
{
    String userMessage = "user> ";
    String input;

    while (getUserPrompt(userMessage, input))
    {
        std::cout << rep(input) << std::endl;
    }

    return 0;
}

bool getUserPrompt(const String& prompt, String& input)
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

String READ(const String& input)
{
    // Testing Reader
    Reader myReader(input);
    myReader.next();
    myReader.peek();

    return input;
}

String EVAL(const String& input)
{
    return input;
}

String PRINT(const String& input)
{
    return input;
}

String rep(const String& input)
{
    return PRINT(EVAL(READ(input)));
}