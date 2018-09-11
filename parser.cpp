#include "parser.h"

Parser::Parser() {
  cout << "Default constructor called. " << endl;
  cout << "Waiting further file initialization...\n " << endl;
  isFileHandlerReady = false;
}

Parser::Parser(int argc, char* argv[]) {
  cout << "Customized constructor called. " << endl;
  getFileHandler(argc, argv);
}

Parser::~Parser() {
  cout << "\nDefault destructor called." << endl;

  if (defHandler) {
    cout << "Closing .def file handler. " << endl;
    defHandler.close();
  }

  if (spefHandler) {
    cout << "Closing .spef file handler. " << endl;
    spefHandler.close();
  }

  if (outputHandler) {
    cout << "Closing output file handler. " << endl;
    outputHandler.close();
  }
  
}

//
int Parser::getFileHandler(int argc, char* argv[]) {
//  defFileName = "", spefFileName = "", outputFileName = "nets.sv";
  isFileHandlerReady = false;

  if (argc<3 || argc>4) {
    cout << "Number of input files is wrong... " << endl;
    cout << "Correct input format: " << endl;
    cout << "  ./parser *.def *.spef [output_filename]" << endl;
    cerr << "Initialization failed. Abort! \n" << endl;
    return 0;
  }
  
  defHandler.open(argv[1]);
  if (!defHandler) {
    cerr << "Unable to open input .def file: " << argv[1] << endl;
    return 0;
  }
  defFileName = argv[1];

  spefHandler.open(argv[2]);
  if (!spefHandler) {
    cerr << "Unable to open input .spef file: " << argv[2] << endl;
    return 0;
  }
  defFileName = argv[2];

  if (argc==3) {
    cout << "Output file unspecified, using default name NETS.CSV." << endl;
    outputHandler.open("nets.csv");
    outputFileName = "nets.csv";
  } else if (argc==4) {
    cout << "Output to specified file name " << argv[3] << endl;
    outputHandler.open(argv[3]);
    outputFileName = argv[3];
  }
  
  cout << "All inputs opened successfully. " << endl;
  isFileHandlerReady = true;
  // 1 for successful openings, 0 for failure
  return 1;
}


int Parser::readDefFile() {
  if (!isFileHandlerReady) {
    cout << "File handlers not ready. Quit reading. " << endl;
    return 0;  
  }

  string line;
  bool isInNETS = false;
  int counter = 0;
  while (getline(defHandler, line)) {
    counter++;
    if (line.find("NETS") == 0) isInNETS = true, cout << counter << endl;
    if (line.find("END NETS") == 0) isInNETS = false, cout << counter << endl;
  }
  return 1;
}

// Display names of input/output files 
void Parser::displayFileInfo() {
  if (isFileHandlerReady) {
    cout << "\nInput .def file: " << defFileName << endl;
    cout << "Input .spef file: " << spefFileName << endl;
    cout << "Input output file: " << outputFileName << endl;
  } else 
    cout << "Fill handler not ready. Check input format/files." << endl;
}
