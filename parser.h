#ifndef PARSER_H
#define PARSER_H
#include <iostream>

using namespace std;

class parser {
  string defFileName;
  string spefFileName;
  string outputFileName;
public:
  parser(int argc, char* argv[]);
};

#endif // PARSER_H
