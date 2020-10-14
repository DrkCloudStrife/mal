#ifndef INC_READER_H
#define INC_READER_H

#include <iostream>
#include <vector>

typedef std::string          String;
typedef std::vector<String>  MalList;
typedef std::vector<MalList> MalArray;

class Reader {
public:
    Reader(const MalList& tokens);

    String next();
    String peek();

private:

    unsigned m_pointer;
    String m_token;
    MalList m_tokens;
};

MalList tokenize(const String& input);
String readStr(const String& input);
void readForm(Reader& reader);
void readList(Reader& reader);
String readAtom(Reader& reader);

#endif // INC_READER_H
