#include "parser.h"

Parser::Parser() {
  cout << "Default constructor called. " << endl;
  cout << "Waiting further file initialization...\n " << endl;
  is_handler_ready = false;
}

Parser::Parser(int argc, char* argv[]) {
  cout << "Customized constructor called. " << endl;
  getFileHandler(argc, argv);
}

Parser::~Parser() {
  cout << "\nDefault destructor called." << endl;

  if (def_handler) {
    cout << "Closing .def file handler. " << endl;
    def_handler.close();
  }

  if (spef_handler) {
    cout << "Closing .spef file handler. " << endl;
    spef_handler.close();
  }

  if (output_handler) {
    cout << "Closing output file handler. " << endl;
    output_handler.close();
  }
  
}

//
int Parser::getFileHandler(int argc, char* argv[]) {
//  defFileName = "", spefFileName = "", outputFileName = "nets.sv";
  is_handler_ready = false;

  if (argc<3 || argc>4) {
    cout << "Number of input files is wrong... " << endl;
    cout << "Correct input format: " << endl;
    cout << "  ./parser *.def *.spef [output_filename]" << endl;
    cerr << "Initialization failed. Abort! \n" << endl;
    return 0;
  }
  
  def_handler.open(argv[1]);
  if (!def_handler) {
    cerr << "Unable to open input .def file: " << argv[1] << endl;
    return 0;
  }
  def_filename = argv[1];

  spef_handler.open(argv[2]);
  if (!spef_handler) {
    cerr << "Unable to open input .spef file: " << argv[2] << endl;
    return 0;
  }
  def_filename = argv[2];

  if (argc==3) {
    cout << "Output file unspecified, using default name NETS.CSV." << endl;
    output_handler.open("nets.csv");
    output_filename = "nets.csv";
  } else if (argc==4) {
    cout << "Output to specified file name " << argv[3] << endl;
    output_handler.open(argv[3]);
    output_filename = argv[3];
  }
  
  cout << "All inputs opened successfully. " << endl;
  is_handler_ready = true;
  // 1 for successful openings, 0 for failure
  return 1;
}

int Parser::readDefFile() {
  if (!is_handler_ready) {
    cout << "File handlers not ready. Quit reading. " << endl;
    return 0;  
  }

  string line;
  bool isInNETS = false;
  unsigned int counter = 0; // line counter for debugging

  while (getline(def_handler, line)) {
    counter++;
    // mark start/end of NETS section
    if (line.find("NETS")==0) isInNETS = true;
    if (line.find("END NETS")==0) isInNETS = false;

    if (isInNETS && line.find("- ")==0) {
      string net_name = line.substr(2);
      vector<Segment> nets;

      string net_line;
      getline(def_handler, net_line), counter++;
      // move to the net
      while (net_line.find("+ ROUTED")==string::npos)
        getline(def_handler, net_line), counter++;
        cout << net_name << " " << counter << endl;

      // read valid lines
      do {
        matchNetLine(net_line, nets);
        getline(def_handler, net_line), counter++;
      } while (net_line.find(";")==string::npos);

        
      
    }
  }

  return 1;
}

// extracting net segment info based on # of spaces inline
// better way with regex ??? 
void Parser::matchNetLine(string net_line, vector<Segment>& nets) {
  unsigned int num_spaces = 0;
  for (char c : net_line)
    if (isspace(c)) num_spaces++;

  net_line.erase(remove(net_line.begin(), net_line.end(), '+'), net_line.end());
  net_line.erase(remove(net_line.begin(), net_line.end(), ')'), net_line.end());
  net_line.erase(remove(net_line.begin(), net_line.end(), '('), net_line.end());

  string head(""), layer(""), via("");
  unsigned int X1(0), Y1(0), X2(0), Y2(0);
  stringstream net_info(net_line);
  if (num_spaces==10)
    net_info >> head >> layer >> X1 >> Y1 >> via;
  else if (num_spaces==13)
    net_info >> head >> layer >> X1 >> Y1 >> X2 >> Y2;
  else if (num_spaces==14)
    net_info >> head >> layer >> X1 >> Y1 >> X2 >> Y2 >> via;
  unsigned int box[4] = {X1, Y1, X2, Y2};

//  cout << num_spaces << " | " << head << " | " << layer << " | " << via << " | ";
//  cout << X1 << " | " << Y1 << " | " << X2 << " | " << Y2 << endl;

  // watch for segment fault here
  Segment seg(layer, box, via);
  nets.push_back(seg);
}

// Display names of input/output files 
void Parser::displayFileInfo() {
  if (is_handler_ready) {
    cout << "\nInput .def file: " << def_filename << endl;
    cout << "Input .spef file: " << spef_filename << endl;
    cout << "Input output file: " << output_filename << endl;
  } else 
    cout << "Fill handler not ready. Check input format/files." << endl;
}
