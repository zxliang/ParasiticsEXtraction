#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
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
public:
  Parser();
  Parser(int argc, char* argv[]);
  ~Parser();

  int getFileHandler(int argc, char* argv[]);
  int readDefFile();
  void matchNetLine(string net_line, vector<Segment>& nets);

  void displayFileInfo();
};

#endif // PARSER_H
