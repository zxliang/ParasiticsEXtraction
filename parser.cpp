#include "parser.h"

parser::parser() {
  cout << "Default constructor called. " << endl;
  cout << "Waiting further file initialization... " << endl;
}

parser::~parser() {
  cout << "Default destructor called." << endl;
}

int parser::getFileHandler(int argc, char* argv[]) {
  if (argc<3) {
    cout << "\nNumber of input files less than 2... " << endl;
    cout << "Correct input format: " << endl;
    cout << "  ./parser *.def *.spef (*output_filename)" << endl;
    cerr << "Initialization failed. Abort! \n" << endl;
    return -1;
  }
  for (int i=0; i<argc; i++)
    cout << argv[i] << endl;

}
