#include "parser.h"

int main(int argc, char* argv[]) {

  //  Initialization parser
//  Parser myParser;
//  myParser.getFileHandler(argc, argv);

  // An alternative way of initialization:
  Parser my_parser(argc, argv);

  // Start to read .def file
  my_parser.readDefFile();

//  Dump input file information:
//  myParser.displayFileInfo();
  return 0;
}
