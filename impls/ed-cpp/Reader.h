#ifndef INC_READER_H
#define INC_READER_H

#include <iostream>
#include <vector>

typedef std::string         String;
typedef std::vector<String> TokenList;

class Reader {
public:
    Reader(const String& input);

    String next();
    String peek();
    void nextToken();
    TokenList tokenize(const String& input);
    void readStr(const String& input);

private:

    String::const_iterator m_start_iter;
    String::const_iterator m_end_iter;
    String m_token;
    TokenList m_tokens;
};

#endif // INC_READER_H