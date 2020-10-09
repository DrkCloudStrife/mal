#include <regex>
#include "Reader.h"
typedef std::regex Regex;
static const Regex PRCE("[\\s,]*(~@|[\\[\\]{}()'`~^@]|\"(?:\\\\.|[^\\\\\"])*\"?|;.*|[^\\s\\[\\]{}('\"`,;)]*)");

Reader::Reader(const String& input)
: m_start_iter(input.begin())
, m_end_iter(input.end())
{
    this->nextToken();
}

// next (method) - Returns token at current position and increments position
String Reader::next()
{
    std::cout << "Calling Next" << std::endl;
    this->nextToken();
    return this->peek();
}

// peek (method) - Returns token at current position
String Reader::peek()
{
    std::cout << "I'm peeking" << std::endl;
    return this->m_token;
}

void Reader::nextToken()
{
    // TODO: Check next token
}

// tokenize (function) - takes a single string and returns array/list of all tokens (strings)
TokenList Reader::tokenize(const String& input)
{
    // TODO: build a tokenizer
    return m_tokens;
}

// readStr (function) - Calls `tokenize` and create new Reader object with tokens
void Reader::readStr(const String& input)
{
    // TokenList tokens = tokenize();
    // read_form
}