#include "parser.h"

int main(int argc, char* argv[]) {

  //  Initialization parser
//  Parser myParser;
//  myParser.getFileHandler(argc, argv);

  // An alternative way of initialization:
  Parser myParser(argc, argv);

  // Start to read .def file
  myParser.readDefFile();

//  Dump input file information:
//  myParser.displayFileInfo();
  return 0;
}
