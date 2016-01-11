#ifndef CALIB_BARREL_RIGHT_OFFSET2_BUNCH3_3_H
#define CALIB_BARREL_RIGHT_OFFSET2_BUNCH3_3_H

#include "tofcalgsec/TofCalib.h"

const int nBarrelRight_Offset2_bunch3_3 = 7;

class calib_barrel_right_offset2_bunch3_3:public TofCalib {
 public:
  calib_barrel_right_offset2_bunch3_3():TofCalib( nBarrelRight_Offset2_bunch3_3 ) {
    m_name = string("calib_barrel_right_offset2_bunch3");
  }

  void calculate_funcs( const Record* r ) {
    return;
  }

  void calculate_y(const Record* r) {
    return;
  }

  void updateData( RecordSet*& data ) {
    return;
  }

};

#endif
