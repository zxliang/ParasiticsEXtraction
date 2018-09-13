#ifndef SEGMENT_H
#define SEGMENT_H
#include <string>

using namespace std;
using SegmentType = unsigned int;
using CoordinateType = int;

class Segment {
  SegmentType type;
  unsigned int length, width;
  string layer;
  string via;
public:
  double R, C, CC;
  CoordinateType coordinates[4];
  CoordinateType total_coordinates[4];

  Segment(string _layer, CoordinateType _coordinates[4], string _via="");
};

#endif // SEGMENT_H
