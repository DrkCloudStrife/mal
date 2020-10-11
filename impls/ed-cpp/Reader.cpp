#include "Reader.h"
#include <regex>

typedef std::regex Regex;
static const Regex PCRE("[\\s,]*(~@|[\\[\\]{}()'`~^@]|\"(?:\\\\.|[^\\\\\"])*\"?|;.*|[^\\s\\[\\]{}('\"`,;)]*)");

// Mark: Reader
Reader::Reader(const MalList& tokens)
: m_pointer(0)
{
    std::cout << "Initiating new reader with " << tokens.size() << " tokens" << std::endl;
    this->m_tokens = tokens;
}

// next (method) - Returns token at current position and increments position
String Reader::next()
{
    std::cout << "Calling Next" << std::endl;
    m_token = this->peek();
    m_pointer += 1;

    std::cout << "Returning: " << m_token << std::endl;
    std::cout << "Next Peek: " << this->peek() << std::endl;

    return m_token;
}

// peek (method) - Returns token at current position
String Reader::peek()
{
    std::cout << "I'm peeking" << std::endl;
    m_token = this->m_tokens.at(this->m_pointer);
    return this->m_token;
}

// tokenize (function) - takes a single string and returns array/list of all tokens (strings)
MalList tokenize(const String& input)
{
    MalList tokens;

    if (std::regex_match(input, PCRE))
    {
        std::cout << "Regex matched" << std::endl;
        std::smatch inputMatches;
        std::regex_match(input, inputMatches, PCRE);
        // std::cout << inputMatches.str() << std::endl;
        for (unsigned i = 0; i < inputMatches.size(); i++)
        {
            tokens.assign(i, inputMatches[i]);
        }
    } else {
        std::cout << "no match, assign whole input" << std::endl;
        tokens.assign(1, input);
    }

    return tokens;
}

// readStr (function) - Calls `tokenize` and create new Reader object with tokens
String readStr(const String& input)
{
    MalList tokens = tokenize(input);
    Reader myReader(tokens);
    return readForm(myReader);
}

String readForm(Reader& reader)
{
    std::cout << reader.peek() << std::endl;
    return "";
}