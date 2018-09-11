#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "segment.h"

using namespace std;

class Parser {
  bool is_handler_ready;
  string def_filename;
  ifstream def_handler;
  string spef_filename;
  ifstream spef_handler;
  string output_filename;
  ofstream output_handler;
  vector<Segment> nets;
public:
  Parser();
  Parser(int argc, char* argv[]);
  ~Parser();

  int getFileHandler(int argc, char* argv[]);
  int readDefFile();
  void matchNetLine(string net_line);

  void displayFileInfo();
};

#endif // PARSER_H
