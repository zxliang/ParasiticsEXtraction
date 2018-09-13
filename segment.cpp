#include "segment.h"

Segment::Segment(string _layer, CoordinateType _coordinates[4], string _via) {
  layer = _layer; // width should be set according to layer
  coordinates[4] = _coordinates[4];
  via = _via;
  if (coordinates[2]==0 && _coordinates[3]==0) {
    type = 1; // via
    length = 0;
  } else if (coordinates[2]==0) {
    type = 2;  // vertical metal
    length = coordinates[3] > coordinates[1] ? coordinates[3] - coordinates[1]
      : coordinates[1] - coordinates[3] ;
  } else if (coordinates[3]==0) {
    type = 3; // horizontal metal
    length = coordinates[2] > coordinates[0] ? coordinates[2] - coordinates[0]
      : coordinates[0] - coordinates[2] ;
  }
};
