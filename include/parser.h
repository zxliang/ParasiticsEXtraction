#ifndef PARSER_H
#define PARSER_H
#include <iostream>

using namespace std;

class parser {
public:
  parser();
  ~parser();
  int getFileHandler(int argc, char* argv[]);
};

#endif // PARSER_H
