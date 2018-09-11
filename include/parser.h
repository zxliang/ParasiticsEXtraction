#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "segment.h"

using namespace std;

class parser {
  string defFileName;
  ifstream defHandler;
  string spefFileName;
  ifstream spefHandler;
  string outputFileName;
  ofstream outputHandler;
  vector<segment> nets;
public:
  parser();
  parser(int argc, char* argv[]);
  ~parser();

  int getFileHandler(int argc, char* argv[]);


  void displayFileInfo();
};

#endif // PARSER_H
