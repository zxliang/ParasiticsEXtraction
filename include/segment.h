#ifndef SEGMENT_H
#define SEGMENT_H
#include <string>

using namespace std;

class Segment {
  string layer;
  string via;
  unsigned int center_coordinates[4];
public:
  Segment(string _layer, unsigned int _center_coordinates[4], string _via="");
};

#endif // SEGMENT_H
