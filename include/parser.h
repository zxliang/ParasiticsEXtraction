#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>

using namespace std;

class parser {
  string defFileName;
  ifstream defHandler;
  string spefFileName;
  ifstream spefHandler;
  string outputFileName;
  ofstream outputHandler;
public:
  parser();
  parser(int argc, char* argv[]);
  ~parser();
  int getFileHandler(int argc, char* argv[]);
  void displayFileInfo();
};

#endif // PARSER_H
