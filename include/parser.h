#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "segment.h"

using namespace std;

class Parser {
  bool isFileHandlerReady;
  string defFileName;
  ifstream defHandler;
  string spefFileName;
  ifstream spefHandler;
  string outputFileName;
  ofstream outputHandler;
  vector<Segment> nets;
public:
  Parser();
  Parser(int argc, char* argv[]);
  ~Parser();

  int getFileHandler(int argc, char* argv[]);
  int readDefFile();

  void displayFileInfo();
};

#endif // PARSER_H
