#include "Reader.h"
#include <regex>

typedef std::regex Regex;
static const Regex PCRE("[\\s,]*(~@|[\\[\\]{}()'`~^@]|\"(?:\\\\.|[^\\\\\"])*\"?|;.*|[^\\s\\[\\]{}('\"`,;)]*)");

// Mark: Reader
Reader::Reader(const MalList& tokens)
: m_pointer(0)
{
    this->m_tokens = tokens;
}

// next (method) - Returns token at current position and increments position
String Reader::next()
{
    m_token = this->peek();
    m_pointer += 1;

    return m_token;
}

// peek (method) - Returns token at current position
String Reader::peek()
{
    m_token = this->m_tokens.at(this->m_pointer);
    return this->m_token;
}

// tokenize (function) - takes a single string and returns array/list of all tokens (strings)
MalList tokenize(const String& input)
{
    MalList tokens;

    for (std::sregex_iterator it = std::sregex_iterator(input.begin(), input.end(), PCRE);
        it != std::sregex_iterator(); it++)
    {
        std::smatch m;
        m = *it;
        String sm = m.str(1);
        tokens.push_back(sm);
    }

    return tokens;
}

// readStr (function) - Calls `tokenize` and create new Reader object with tokens
String readStr(const String& input)
{
    MalList tokens = tokenize(input);
    Reader myReader(tokens);
    readForm(myReader);

    return input;
}

// readForm (function) - Peeks first token in Reader and switch on the first character of the token
// TODO: Create a pointer template that returns different malTypes
void readForm(Reader& reader)
{
    String token = reader.peek();
    if (token == "(") {
        reader.next();
        return readList(reader);
    }

    readAtom(reader);
}

// readList (function) - Repeately calls `readForm` until ')' token is found
void readList(Reader& reader)
{
    String token = reader.peek();
    MalList tokens;
    while(token != ")") {
        readForm(reader);
        tokens.push_back(token);
    }
}

String readAtom(Reader& reader)
{
    String token = reader.next();
    return token;
}
